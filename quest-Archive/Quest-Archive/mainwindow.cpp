#include "mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QHeaderView>

#include <QFile>
#include <QTextStream>

// =====================================
// Constructor
// =====================================

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    loadData();
}

// =====================================
// Destructor
// =====================================

MainWindow::~MainWindow()
{
    saveData();
}

// =====================================
// Setup UI
// =====================================

void MainWindow::setupUI()
{
    setWindowTitle("Quest Archive Manager");
    resize(900, 600);

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    table = new QTableWidget();

    table->setColumnCount(5);

    table->setHorizontalHeaderLabels({
        "Name",
        "Level",
        "Quests",
        "Gold",
        "Rank"
    });

    table->horizontalHeader()
        ->setSectionResizeMode(QHeaderView::Stretch);

    addButton = new QPushButton("Add Adventurer");
    deleteButton = new QPushButton("Delete");
    questButton = new QPushButton("Record Quest");
    sortButton = new QPushButton("Sort By Gold");
    statsButton = new QPushButton("Statistics");
    saveButton = new QPushButton("Save");
    loadButton = new QPushButton("Load");

    QHBoxLayout* buttonLayout = new QHBoxLayout();

    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(questButton);
    buttonLayout->addWidget(sortButton);
    buttonLayout->addWidget(statsButton);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(loadButton);

    QVBoxLayout* mainLayout = new QVBoxLayout();

    mainLayout->addWidget(table);
    mainLayout->addLayout(buttonLayout);

    centralWidget->setLayout(mainLayout);

    connect(addButton,
            &QPushButton::clicked,
            this,
            &MainWindow::addAdventurer);

    connect(deleteButton,
            &QPushButton::clicked,
            this,
            &MainWindow::deleteAdventurer);

    connect(questButton,
            &QPushButton::clicked,
            this,
            &MainWindow::recordQuest);

    connect(sortButton,
            &QPushButton::clicked,
            this,
            &MainWindow::sortByGold);

    connect(statsButton,
            &QPushButton::clicked,
            this,
            &MainWindow::showStatistics);

    connect(saveButton,
            &QPushButton::clicked,
            this,
            &MainWindow::saveData);

    connect(loadButton,
            &QPushButton::clicked,
            this,
            &MainWindow::loadData);
}

// =====================================
// Refresh Table
// =====================================

void MainWindow::refreshTable()
{
    table->setRowCount(guild.size());

    for (int i = 0; i < guild.size(); i++)
    {
        table->setItem(
            i,
            0,
            new QTableWidgetItem(
                QString::fromStdString(
                    guild[i].getName())));

        table->setItem(
            i,
            1,
            new QTableWidgetItem(
                QString::number(
                    guild[i].getLevel())));

        table->setItem(
            i,
            2,
            new QTableWidgetItem(
                QString::number(
                    guild[i].getQuestsCompleted())));

        table->setItem(
            i,
            3,
            new QTableWidgetItem(
                QString::number(
                    guild[i].getGoldEarned())));

        table->setItem(
            i,
            4,
            new QTableWidgetItem(
                QString::fromStdString(
                    guild[i].getRank())));
    }
}

// =====================================
// Add Adventurer
// =====================================

void MainWindow::addAdventurer()
{
    bool ok;

    QString name = QInputDialog::getText(
        this,
        "Add Adventurer",
        "Enter Name:",
        QLineEdit::Normal,
        "",
        &ok);

    if (!ok || name.isEmpty())
    {
        return;
    }

    int level = QInputDialog::getInt(
        this,
        "Level",
        "Enter Starting Level:",
        1,
        1,
        100,
        1,
        &ok);

    if (!ok)
    {
        return;
    }

    guild.append(
        Adventurer(
            name.toStdString(),
            level));

    refreshTable();
}

// =====================================
// Delete Adventurer
// =====================================

void MainWindow::deleteAdventurer()
{
    int row = table->currentRow();

    if (row < 0)
    {
        QMessageBox::warning(
            this,
            "Delete",
            "Please select an adventurer.");

        return;
    }

    guild.remove(row);

    refreshTable();
}

// =====================================
// Record Quest
// =====================================

void MainWindow::recordQuest()
{
    int row = table->currentRow();

    if (row < 0)
    {
        QMessageBox::warning(
            this,
            "Record Quest",
            "Select an adventurer first.");

        return;
    }

    bool ok;

    double reward = QInputDialog::getDouble(
        this,
        "Quest Reward",
        "Gold Reward:",
        100,
        0,
        100000,
        2,
        &ok);

    if (!ok)
    {
        return;
    }

    guild[row].recordQuest(reward);

    refreshTable();
}

// =====================================
// Sort By Gold
// =====================================

void MainWindow::sortByGold()
{
    for (int i = 0; i < guild.size() - 1; i++)
    {
        int maxIndex = i;

        for (int j = i + 1; j < guild.size(); j++)
        {
            if (guild[j].getGoldEarned() >
                guild[maxIndex].getGoldEarned())
            {
                maxIndex = j;
            }
        }

        guild.swapItemsAt(i, maxIndex);
    }

    refreshTable();
}

// =====================================
// Statistics
// =====================================

void MainWindow::showStatistics()
{
    if (guild.isEmpty())
    {
        QMessageBox::information(
            this,
            "Statistics",
            "No adventurers found.");

        return;
    }

    double totalGold = 0;
    int totalLevels = 0;
    int totalQuests = 0;

    for (const auto& adventurer : guild)
    {
        totalGold += adventurer.getGoldEarned();
        totalLevels += adventurer.getLevel();
        totalQuests += adventurer.getQuestsCompleted();
    }

    double averageLevel =
        static_cast<double>(totalLevels)
        / guild.size();

    QString stats;

    stats += "Total Adventurers: "
             + QString::number(guild.size())
             + "\n";

    stats += "Average Level: "
             + QString::number(averageLevel, 'f', 2)
             + "\n";

    stats += "Total Quests Completed: "
             + QString::number(totalQuests)
             + "\n";

    stats += "Total Gold Earned: "
             + QString::number(totalGold);

    QMessageBox::information(
        this,
        "Guild Statistics",
        stats);
}

// =====================================
// Save Data
// =====================================

void MainWindow::saveData()
{
    QFile file("quests.txt");

    if (!file.open(QIODevice::WriteOnly))
    {
        return;
    }

    QTextStream out(&file);

    for (const auto& adventurer : guild)
    {
        out
            << QString::fromStdString(
                   adventurer.getName())
            << ","
            << adventurer.getLevel()
            << ","
            << adventurer.getQuestsCompleted()
            << ","
            << adventurer.getGoldEarned()
            << ","
            << QString::fromStdString(
                   adventurer.getRank())
            << "\n";
    }

    file.close();
}

// =====================================
// Load Data
// =====================================

void MainWindow::loadData()
{
    guild.clear();

    QFile file("quests.txt");

    if (!file.open(QIODevice::ReadOnly))
    {
        refreshTable();
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd())
    {
        QString line = in.readLine();

        QStringList fields =
            line.split(',');

        if (fields.size() != 5)
        {
            continue;
        }

        guild.append(
            Adventurer(
                fields[0].toStdString(),
                fields[1].toInt(),
                fields[2].toInt(),
                fields[3].toDouble(),
                fields[4].toStdString()
                ));
    }

    file.close();

    refreshTable();
}