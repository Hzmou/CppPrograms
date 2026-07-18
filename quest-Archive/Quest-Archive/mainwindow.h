#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTableWidget>
#include <QPushButton>
#include <QWidget>

#include "Adventurer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QVector<Adventurer> guild;

    QWidget* centralWidget;

    QTableWidget* table;

    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* sortButton;
    QPushButton* statsButton;
    QPushButton* saveButton;
    QPushButton* loadButton;
    QPushButton* questButton;

    void setupUI();
    void refreshTable();

    void saveData();
    void loadData();

private slots:
    void addAdventurer();
    void deleteAdventurer();
    void sortByGold();
    void showStatistics();
    void recordQuest();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif