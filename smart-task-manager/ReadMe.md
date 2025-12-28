
# Smart Task Manager (C++) — Medium-Sized Project

A console-based **Smart Task Manager** to organize tasks into projects, schedule them by priority and due dates, tag and search tasks, and persist data to disk. This README contains **project instructions** and all **header files**. A starter `main.cpp` is provided separately.

---

## 🎯 Goals
- Practice **object-oriented design** with **7 classes** + an `Application` main class.
- Use multiple **standard data structures**: `std::vector`, `std::unordered_map`, `std::priority_queue`, `std::set`, `std::optional`.
- Implement **basic persistence** (text or JSON-like) and **CLI commands**.
- Write clean, testable C++17/20 code with separation of interface (`.hpp`) and implementation (`.cpp`).

---

## 🧱 Project Overview
CLI app that manages tasks grouped by projects, with tags, ownership, and scheduling. Supports:

- Create, update, delete tasks & projects
- Assign tasks to users
- Tag tasks and filter/search by tag
- Prioritize tasks via a scheduler (priority queue based on urgency)
- Persist and load state
- Simple command loop (add/list/done/schedule/save/load)

---

## 📁 Suggested Folder Structure
```
smart-task-manager/
  include/
    Application.hpp
    Task.hpp
    Project.hpp
    User.hpp
    TagManager.hpp
    TaskRepository.hpp
    Scheduler.hpp
    Persistence.hpp
  src/
    (your .cpp implementations go here)
    main.cpp
  data/
    (optional: saved snapshots)
  tests/
    (optional)
  CMakeLists.txt
  README.md (this file)
```

---

## 🛠️ Build Requirements
- C++17 or C++20 compiler (GCC/Clang/MSVC)
- CMake 3.15+

### Example `CMakeLists.txt`
```cmake
cmake_minimum_required(VERSION 3.15)
project(SmartTaskManager CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SRC "src/*.cpp")
add_executable(smt ${SRC})
```

---

## 🧪 Example CLI Commands (spec)
- `project add <name>` — create project
- `task add <project> <title> --due YYYY-MM-DD --est 2h --tags tag1,tag2`
- `task list [--project <name>] [--tag <tag>] [--user <username>]`
- `task done <task_id>`
- `user add <username> <display_name>`
- `tag rename <old> <new>`
- `schedule next`
- `save <path>` / `load <path>`
- `exit`

---

## 🧩 Class Diagram (high-level)
```
Application
  ├── TaskRepository
  │     ├── Project
  │     └── Task
  ├── User
  ├── TagManager
  ├── Scheduler
  └── Persistence
```

---

## ✅ Requirements Checklist
- [ ] Implement all headers below in corresponding `.cpp` files
- [ ] Use `std::vector`, `std::unordered_map`, and `std::priority_queue` at minimum
- [ ] Add error handling (`std::optional`, exceptions or error codes)
- [ ] Unit-test at least repository and scheduler
- [ ] Document methods and invariants in code comments

---

## 📄 Header Files
> **Note:** Interfaces are intentionally compact but realistic. Feel free to extend.

### `include/Task.hpp`
```cpp
#pragma once
#include <string>
#include <vector>
#include <set>
#include <optional>
#include <chrono>

namespace stm {

using Date = std::chrono::system_clock::time_point;

enum class TaskStatus { Todo, InProgress, Done, Archived };

struct Estimate {
    int minutes = 0;
    int points = 0; // optional agile-like points
};

class Task {
public:
    Task() = default;
    Task(int id, std::string title);

    int id() const noexcept;
    const std::string& title() const noexcept;

    void set_title(std::string t);
    void set_description(std::string d);
    void set_due(Date d);
    void set_estimate(Estimate e);
    void set_status(TaskStatus s);
    void set_project(std::string name);
    void assign_user(std::string username);

    const std::string& description() const noexcept;
    std::optional<Date> due() const noexcept;
    std::optional<Estimate> estimate() const noexcept;
    TaskStatus status() const noexcept;
    const std::string& project() const noexcept;
    const std::optional<std::string>& assignee() const noexcept;

    bool add_tag(const std::string& tag);
    bool remove_tag(const std::string& tag);
    const std::set<std::string>& tags() const noexcept;

private:
    int m_id = -1;
    std::string m_title;
    std::string m_description;
    std::optional<Date> m_due;
    std::optional<Estimate> m_estimate;
    TaskStatus m_status = TaskStatus::Todo;
    std::string m_project; // project name
    std::optional<std::string> m_assignee; // username
    std::set<std::string> m_tags; // ordered for stable output
};

} // namespace stm
```

### `include/Project.hpp`
```cpp
#pragma once
#include <string>

namespace stm {

class Project {
public:
    Project() = default;
    explicit Project(std::string name);

    const std::string& name() const noexcept;
    const std::string& description() const noexcept;

    void set_description(std::string d);

    void set_color(std::string hex);
    const std::string& color() const noexcept;

private:
    std::string m_name;
    std::string m_description;
    std::string m_color; // #RRGGBB
};

} // namespace stm
```

### `include/User.hpp`
```cpp
#pragma once
#include <string>
#include <set>

namespace stm {

class User {
public:
    User() = default;
    User(std::string username, std::string display_name);

    const std::string& username() const noexcept;
    const std::string& display_name() const noexcept;

    void set_display_name(std::string dn);

    void set_default_project(std::string project);
    const std::string& default_project() const noexcept;

    bool add_skill(const std::string& tag);
    bool remove_skill(const std::string& tag);
    const std::set<std::string>& skills() const noexcept;

private:
    std::string m_username;
    std::string m_display_name;
    std::string m_default_project;
    std::set<std::string> m_skills;
};

} // namespace stm
```

### `include/TagManager.hpp`
```cpp
#pragma once
#include <string>
#include <unordered_map>
#include <set>

namespace stm {

class TagManager {
public:
    bool add(const std::string& tag);
    bool remove(const std::string& tag);
    bool rename(const std::string& old_tag, const std::string& new_tag);

    size_t count(const std::string& tag) const;
    std::set<std::string> all() const; // sorted output

    void increment(const std::string& tag);
    void decrement(const std::string& tag);

private:
    std::unordered_map<std::string, size_t> m_counts;
};

} // namespace stm
```

### `include/TaskRepository.hpp`
```cpp
#pragma once
#include <vector>
#include <unordered_map>
#include <optional>
#include <string>
#include "Task.hpp"
#include "Project.hpp"
#include "User.hpp"

namespace stm {

class TaskRepository {
public:
    // Projects
    bool add_project(const Project& p);
    bool remove_project(const std::string& name);
    std::optional<Project> get_project(const std::string& name) const;
    std::vector<Project> list_projects() const;

    // Users
    bool add_user(const User& u);
    bool remove_user(const std::string& username);
    std::optional<User> get_user(const std::string& username) const;
    std::vector<User> list_users() const;

    // Tasks
    int next_task_id() const;
    bool add_task(const Task& t);
    bool update_task(const Task& t);
    bool remove_task(int id);
    std::optional<Task> get_task(int id) const;
    std::vector<Task> list_tasks() const;

    // Filtering
    std::vector<Task> tasks_by_project(const std::string& project) const;
    std::vector<Task> tasks_by_tag(const std::string& tag) const;
    std::vector<Task> tasks_by_user(const std::string& username) const;

private:
    std::unordered_map<std::string, Project> m_projects;
    std::unordered_map<std::string, User> m_users;
    std::unordered_map<int, Task> m_tasks;
};

} // namespace stm
```

### `include/Scheduler.hpp`
```cpp
#pragma once
#include <queue>
#include <vector>
#include <functional>
#include "Task.hpp"

namespace stm {

using UrgencyFn = std::function<double(const Task&)>;

class Scheduler {
public:
    explicit Scheduler(UrgencyFn fn);

    void load(const std::vector<Task>& tasks);
    void clear();

    bool empty() const noexcept;
    size_t size() const noexcept;

    const Task& peek() const; // throws if empty
    Task pop(); // throws if empty

private:
    struct Node {
        double score;
        Task task;
        bool operator<(const Node& other) const { return score < other.score; } // max-heap
    };

    std::priority_queue<Node> m_pq;
    UrgencyFn m_urgency;
};

} // namespace stm
```

### `include/Persistence.hpp`
```cpp
#pragma once
#include <string>
#include <vector>
#include "Task.hpp"
#include "Project.hpp"
#include "User.hpp"

namespace stm {

class Persistence {
public:
    bool save(const std::string& path,
              const std::vector<Project>& projects,
              const std::vector<User>& users,
              const std::vector<Task>& tasks) const;

    bool load(const std::string& path,
              std::vector<Project>& projects,
              std::vector<User>& users,
              std::vector<Task>& tasks) const;
};

} // namespace stm
```

### `include/Application.hpp`
```cpp
#pragma once
#include <string>
#include "TaskRepository.hpp"
#include "TagManager.hpp"
#include "Scheduler.hpp"
#include "Persistence.hpp"

namespace stm {

class Application {
public:
    Application();
    int run();

private:
    void handle_project_add(const std::string& name);
    void handle_user_add(const std::string& username, const std::string& display);
    void handle_task_add(const std::string& project, const std::string& title);
    void handle_task_done(int id);
    void handle_task_list(const std::string& filter_kind = "", const std::string& filter_value = "");
    void handle_schedule_next();
    void handle_save(const std::string& path);
    void handle_load(const std::string& path);

    static double default_urgency(const Task& t);

private:
    TaskRepository m_repo;
    TagManager m_tags;
    Scheduler m_sched;
    Persistence m_persist;
};

} // namespace stm
```

---

## 🧭 Implementation Hints
- Urgency: Combine due date proximity, status, and estimate.
- Dates: parse `YYYY-MM-DD` or use `std::chrono`.
- Persistence: human-readable; serialize per entity type.
- Error handling: prefer `std::optional` for lookups.
- Testing: mock tasks and validate scheduler ordering.

---

## 🚀 Stretch Ideas
- Colored terminal output
- Export to CSV
- Recurring tasks / reminders

---

## 📌 Deliverables
- Header interfaces unchanged (you may add methods but don’t remove existing ones)
- `.cpp` implementations for each header
- A `main.cpp` that constructs `Application` and calls `run()`

