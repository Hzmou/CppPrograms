
```cpp

// ...existing code...
/*
Impelementation
*/
#include "Task.hpp"
#include <utility>

namespace stm {

Task::Task(int id, std::string title)
    : m_id(id), m_title(std::move(title)) {}

int Task::id() const noexcept {
    return m_id;
}

const std::string& Task::title() const noexcept {
    return m_title;
}

void Task::set_title(std::string t) {
    m_title = std::move(t);
}

void Task::set_description(std::string d) {
    m_description = std::move(d);
}

void Task::set_due(Date d) {
    m_due = d;
}

void Task::set_estimate(Estimate e) {
    m_estimate = e;
}

void Task::set_status(TaskStatus s) {
    m_status = s;
}

void Task::set_project(std::string name) {
    m_project = std::move(name);
}

void Task::assign_user(std::string username) {
    if (username.empty()) m_assignee.reset();
    else m_assignee = std::move(username);
}

const std::string& Task::description() const noexcept {
    return m_description;
}

std::optional<Date> Task::due() const noexcept {
    return m_due;
}

std::optional<Estimate> Task::estimate() const noexcept {
    return m_estimate;
}

TaskStatus Task::status() const noexcept {
    return m_status;
}

const std::string& Task::project() const noexcept {
    return m_project;
}

const std::optional<std::string>& Task::assignee() const noexcept {
    return m_assignee;
}

bool Task::add_tag(const std::string& tag) {
    return m_tags.insert(tag).second;
}

bool Task::remove_tag(const std::string& tag) {
    return m_tags.erase(tag) > 0;
}

const std::set<std::string>& Task::tags() const noexcept {
    return m_tags;
}

} // namespace stm
// ...existing code...