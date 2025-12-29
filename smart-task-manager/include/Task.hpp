
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
    // time in minutes; optional complexity points
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

    // Tag operations
    bool add_tag(const std::string& tag);
    bool remove_tag(const std::string& tag);
    const std::set<std::string>& tags() const noexcept;

private:
    int m_id = -1;  // unique identifier for a task.
    std::string m_title;  // brief title of the task. 
    std::string m_description;  // detailed description of the task.
    std::optional<Date> m_due;  // optional due date.
    std::optional<Estimate> m_estimate;
    TaskStatus m_status = TaskStatus::Todo;
    std::string m_project; // project name
    std::optional<std::string> m_assignee; // username
    std::set<std::string> m_tags; // ordered for stable output
};

} // namespace stm
