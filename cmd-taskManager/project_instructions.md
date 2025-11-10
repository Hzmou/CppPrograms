# C++ Intermediate Project: Command-Line Task Manager

## Project Description

Build a command-line program in C++ that allows a user to manage a list of tasks (add, list, mark as complete, delete) with persistent storage using file I/O.

---

## Core Features

1. **Task Class**
    - Encapsulate details: unique ID, description, and completion status (optionally due date, priority).
2. **Task Storage**
    - Store all tasks in a container (e.g. `std::vector<Task>`).
3. **Command-Line Menu**
    - Display a user menu:
        - Add new task
        - List tasks
        - Mark task as complete
        - Delete task
        - Save tasks to file
        - Load tasks from file
        - Exit
4. **Save and Load**
    - Implement saving/loading tasks to/from a plain text file using file I/O.
5. **Input Validation**
    - Robust checks for user choices and input where appropriate.

---

## Optional Advanced Features

- Sort tasks (by status, id, due date, or priority)
- Search/filter tasks
- Enhanced task details (subtasks, tags, etc.)
- Colored output for UI clarity

---

## Recommended Files

- `main.cpp` – main program & menu logic
- `Task.h` – class declaration only
- `Task.cpp` – class implementation

---

## Task Class Declaration Example (`Task.h`)

```cpp
#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    Task(int _id, const std::string& desc);
    int getId() const;
    std::string getDescription() const;
    bool isCompleted() const;
    void setDescription(const std::string& desc);
    void markComplete();
    void markIncomplete();
private:
    int id;
    std::string description;
    bool completed;
};

#endif // TASK_H
```

---

## Sample Menu Loop and Function Prototypes (`main.cpp`)

```cpp
#include <iostream>
#include <vector>
#include <string>
#include "Task.h"

void showMenu();
void addTask(std::vector<Task>& tasks, int& nextId);
void listTasks(const std::vector<Task>& tasks);
void markTaskComplete(std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);
void saveTasks(const std::vector<Task>& tasks, const std::string& filename);
void loadTasks(std::vector<Task>& tasks, int& nextId, const std::string& filename);

int main() {
    std::vector<Task> tasks;
    int nextId = 1;
    std::string filename = "tasks.txt";

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
}
```

---

## Instructions

1. Declare the `Task` class in `Task.h`, and implement it in `Task.cpp`.
2. Implement the stub functions in `main.cpp` and complete the menu logic.
3. Ensure tasks can be saved to, and loaded from, a text file using C++ file I/O.
4. Test that all menu options function as expected.

---

## Hints

- Use `std::getline` for safe string input.
- Use CSV-like or custom delimiter format for saving/loading.
- Separate logic and UI for clean code.
- Expand features after base implementation is complete.

---

## (Optional) How to Convert to PDF

- **With pandoc:**  
  `pandoc project_instructions.md -o project_instructions.pdf`
- **With VSCode:**  
  Open .md, right-click, "Markdown PDF: Export (pdf)"
- **Online:**  
  Copy/paste into a site like https://markdowntopdf.com/

---