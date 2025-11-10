#include <iostream>
#include <vector>
#include <string>
#include "Task.h"

// ------- Function Prototypes -------
void showMenu();
void addTask(std::vector<Task>& tasks, int& nextId);
void listTasks(const std::vector<Task>& tasks);
void markTaskComplete(std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);
void saveTasks(const std::vector<Task>& tasks, const std::string& filename);
void loadTasks(std::vector<Task>& tasks, int& nextId, const std::string& filename);

// ------- Main -------
int main() {
    std::vector<Task> tasks;
    int nextId = 1;
    std::string filename = "tasks.txt";
    
    // Optionally: loadTasks(tasks, nextId, filename); on startup

    while (true) {
        showMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: addTask(tasks, nextId); break;
            case 2: listTasks(tasks); break;
            case 3: markTaskComplete(tasks); break;
            case 4: deleteTask(tasks); break;
            case 5: saveTasks(tasks, filename); break;
            case 6: loadTasks(tasks, nextId, filename); break;
            case 0: std::cout << "Goodbye!\n"; return 0;
            default: std::cout << "Invalid choice!\n";
        }
    }
    return 0;
}

// ------- Menu & Placeholders -------
void showMenu() {
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