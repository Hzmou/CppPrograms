#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include "Task.h"

using namespace std;

/*
 * cmd-taskManager — simple command-line task manager
 * - Stores tasks in memory and can save/load to "tasks.txt"
 * - Provides an interactive menu to add, list, complete, delete tasks
 *
 * The functions below are defined later in this file.
 */

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

    // Main interactive loop: show menu, read choice, dispatch action
    while (true)
    {
        showMenu();
        int choice;
        // Read user's menu choice (integer expected)
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

// Implementations of task operations follow.

/*
 * addTask:
 * - Prompts the user for a task description (can include spaces).
 * - Creates a new Task with `nextId`, appends it to `tasks`, and increments `nextId`.
 * - If the user input is empty, does not add a task.
 */

void addTask(vector<Task> &tasks, int &nextId)
{

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string taskDesc;

    cout << "Enter the taks that you want to add:   ";
    getline(cin, taskDesc);

    if (taskDesc.empty())
    {
        cout << "No task added. Could not add task.\n";
        return;
    }

    Task newT(nextId, taskDesc);
    tasks.push_back(newT);
    cout << "New task added, ID: #" << nextId << ".\n";
    ++nextId;
}

/*
 * listTasks:
 * - Prints all tasks with ID, completion marker, and description.
 * - If no tasks exist, prints an informational message and returns.
 */

void listTasks(const std::vector<Task> &tasks)
{

    if (tasks.empty())
    {

        cout << "No tasks available.\n";
        return;
    }

    cout << "\n -----  Current Tasks: ------- \n";

    for (const auto &t : tasks)
    {
        cout << "ID #" << t.getId()
             << " [" << (t.isCompleted() ? "X" : " ") << "] "
             << t.getDescription() << '\n';
    }
}

/*
 * markTaskComplete:
 * - Prompts for a task ID and marks the matching task complete.
 * - Validates numeric input and reports if the task is not found.
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
                cout << "Task with ID: #" << id << " is already complete!\n";
            }
            else
            {
                t.markComplete();
                cout << "Task #" << id << " marked as complete.\n";
            }
            return;
        }
    }

    cout << "Task with ID #" << id << " not found.\n";
}

/*
 * deleteTask:
 * - Prompts for a task ID and removes the matching task from the vector.
 * - Validates numeric input and reports success or failure.
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
            tasks.erase(tasks.begin() + i);
            cout << "Task #" << id << " deleted.\n";
            return;
        }
    }

    cout << "Task with ID #" << id << " not found.\n";
}

/*
 * saveTasks:
 * - Writes each task to `filename` in a CSV-like format: id,completed,"description"
 * - Escapes embedded quotes (as doubled quotes) and newlines (as \n) so description
 *   can be round-tripped by `loadTasks`.
 */

/*
 * loadTasks:
 * - Reads tasks from `filename` using the CSV-like format written by `saveTasks`.
 * - Reconstructs each Task, restores completion state, and updates `nextId`.
 * - Handles quoted descriptions, doubled quotes, and \n sequences.
 */

void loadTasks(vector<Task> &tasks, int &nextId, const string &filename)
{
    cout << "no taks in the list to save, Please add tasks!";
    return;

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

/*

*


*/

void loadTasks(vector<Task> &tasks, int &nextId, const string &filename)
{

    ifstream ifs(filename);

    if (!ifs)
    {

        cout << "Failed to open file: " << filename << " for reading." << endl;
        return;
    }

    // clear the vector of tasks.

    tasks.clear();
    nextId = 1;
    int maxId = 0;

    string line;

    // reading from the file.

    while (getline(ifs, line))
    {

        if (line.empty())
        {
            // skip empty lines
            continue;
        }

        size_t pos = 0;
        size_t comma = line.find(',', pos);

        if (comma == string::npos)
        {
            std::cout << "Skipping malformed line: " << line << '\n';
        }

        string idStr = line.substr(pos, comma - pos);
        pos = comma + 1;

        // parse completed.

        comma = line.find(',', pos);

        if (comma == string::npos)
        {
            cout << "Skipping malformed line: " << line << '\n';
            continue;
        }

        string compStr = line.substr(pos, comma - pos);
        pos = comma + 1;

        // parse quoted description (CSV-like),
        // handle doubled quotes and \n sequences.

        string desc;

        if (pos < line.size() && line[pos] == '"')
        {

            size_t i = pos + 1;

            while (i < line.size())
            {
                char c = line[i];
                if (c == '"')
                {
                    // doubled quote -> literal quote
                    if (i + 1 < line.size() && line[i + 1] == '"')
                    {
                        desc.push_back('"');
                        i += 2;
                        continue;
                    }
                    else
                    {
                        // closing quote
                        ++i;
                        break;
                    }
                }
                if (c == '\\' && i + 1 < line.size() && line[i + 1] == 'n')
                {
                    desc.push_back('\n');
                    i += 2;
                    continue;
                }
                desc.push_back(c);
                ++i;
            }
        }
        else
        {

            // no quotes -- take rest

            desc = line.substr(pos);
        }

        try
        {
            int id = stoi(idStr);
            int completed = stoi(compStr);

            // create task and set completed flag
            Task t(id, desc);
            if (completed != 0)
                t.markComplete();
            tasks.push_back(t);
            if (id > maxId)
                maxId = id;
        }
        catch (const exception &)
        {
            cout << "Skipping line with bad numeric fields:" << line << '\n';
            continue;
        }
    }

    if (maxId >= nextId)
    {

        nextId = maxId + 1;
    }

    cout << "Loaded " << tasks.size() << " tasks from " << filename << "." << endl;
}
