
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
