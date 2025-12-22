#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include "Task.h"

using namespace std;

// ------- Function Prototypes -------
void showMenu();
void addTask(std::vector<Task> &tasks, int &nextId);
void listTasks(const std::vector<Task> &tasks);
void markTaskComplete(std::vector<Task> &tasks);
void deleteTask(std::vector<Task> &tasks);
void saveTasks(const std::vector<Task> &tasks, const std::string &filename);
void loadTasks(std::vector<Task> &tasks, int &nextId, const std::string &filename);

// ------- Main -------
int main()
{
    std::vector<Task> tasks;
    int nextId = 1;
    std::string filename = "tasks.txt";

    // Optionally: loadTasks(tasks, nextId, filename); on startup

    while (true)
    {
        showMenu();
        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addTask(tasks, nextId);
            break;
        case 2:
            listTasks(tasks);
            break;
        case 3:
            markTaskComplete(tasks);
            break;
        case 4:
            deleteTask(tasks);
            break;
        case 5:
            saveTasks(tasks, filename);
            break;
        case 6:
            loadTasks(tasks, nextId, filename);
            break;
        case 0:
            std::cout << "Goodbye!\n";
            return 0;
        default:
            std::cout << "Invalid choice!\n";
        }
    }
    return 0;
}

// ------- Menu & Placeholders -------
void showMenu()
{
    std::cout << "\n---- Task Manager ----\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. List Tasks\n";
    std::cout << "3. Mark Task as Complete\n";
    std::cout << "4. Delete Task\n";
    std::cout << "5. Save Tasks\n";
    std::cout << "6. Load Tasks\n";
    std::cout << "0. Exit\n";
    std::cout << "Select option: ";
}

// Implement: addTask, listTasks, markTaskComplete, deleteTask, saveTasks, loadTasks
// (Leave as empty stubs first, fill in as you go!)

// implementation of all the fucntion above.

/*
 * This function add a task to the task vector.
 */

void addTask(vector<Task> &tasks, int &nextId)
{

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string taskDesc;

    cout << "Enter the taks that you want to add:   ";
    getline(cin, taskDesc);

    if (taskDesc.empty())
    {

        cout << "No task Added. could not add Task.  ";
        return;

        Task newT(nextId, taskDesc);

        // add the new task to the vector of tasks that already exists.

        tasks.push_back(newT);
        cout << "New task added , ID: # " << nextId << ".\n";
        ++nextId;
    }
}

/*
 * list all tasks that are current in the terminal.
 */

void listTasks(const std::vector<Task> &tasks)
{

    if (tasks.empty())
    {

        cout << "No tasks available.\n";
        return;
    }

    cout << "\n -----  Current Tasks: ------- \n";

    for (auto &t : tasks)
    {

        cout << "ID #" << t.getId()
             << " [" << (t.isCompleted() ? "X" : " ") << "] "
             << t.getDescription() << '\n';
    }
}

/*
 * Mark a task if it's complete.
 */
void markTaskComplete(std::vector<Task> &tasks)
{

    if (tasks.empty())
    {

        cout << "No tasks in the list to mark! Please add a task to the list.\n";
        return;
    }

    cout << "Enter task ID to mark as complete: ";

    int id;

    if (!(cin >> id))
    {

        cout << "Invalid Input.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (auto &t : tasks)
    {

        if (t.getId() == id)
        {

            if (t.isCompleted())
            {
                cout << "Task with ID: #" << id << "is already compelete!";
            }
            else
            {
                t.markComplete();
                cout << "Task #" << id << "marked as compelete.\n";
            }
        }

        return;
    }

    cout << "Task with ID #" << id << " not found.\n";
}

/*
 * function to delete a task from the vector list of the tasks.
 */

void deleteTask(std::vector<Task> &tasks)
{

    if (tasks.empty())
    {

        cout << "No tasks in the list to delete, Please add tasks.";
        return;
    }

    cout << "Please enter the task ID # to delete: ";
    int id;

    if (!(cin >> id))
    {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i)
    {

        if (tasks[i].getId() == id)
        {

            tasks.erase(tasks.begin() + 1);
            cout << "Task #" << id << " deleted.\n";
            return;
        }
    }

    cout << "Task with ID #" << id << " not found.\n";
}

/*
 * save tasks into the file (.txt).
 */

void saveTasks(const std::vector<Task> &tasks, const std::string &filename)
{

    if (tasks.empty())
    {

        cout << "no taks in the list to save, Please add tasks!";
        return;
    }

    // write content of the vector tasks into a .txt file with "filename".

    // opens a file for writing and truncates any existing content.

    ofstream ofs(filename, ios::trunc);

    if (!ofs)
    {
        cout << "Failed to open '" << filename << "' for writing.\n";
        return;
    }

    for (auto &t : tasks)
    {

        string desc = t.getDescription();
        string esc;
        esc.reserve(desc.size());

        for (char c : desc)
        {
            if (c == '"')
            {
                esc += "\"\""; // double quotes for CSV-safe quoting
            }
            else if (c == '\n')
            {
                esc += "\\n";
            }
            else
            {
                esc.push_back(c);
            }
        }
        ofs << t.getId() << ',' << (t.isCompleted() ? 1 : 0) << ",\"" << esc << "\"\n";
    }

    ofs.close();

    if (!ofs)
    {

        cout << "Error occured while writing to' " << filename << "' .\n";
    }
    else
    {
        cout << "Tasks saved to '" << filename << "'.\n";
    }
}

