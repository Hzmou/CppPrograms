
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

    // Runs the main CLI loop
    int run();

private:
    // command handlers
    void handle_project_add(const std::string& name);
    void handle_user_add(const std::string& username, const std::string& display);
    void handle_task_add(const std::string& project, const std::string& title);
    void handle_task_done(int id);
    void handle_task_list(const std::string& filter_kind = "", const std::string& filter_value = "");
    void handle_schedule_next();
    void handle_save(const std::string& path);
    void handle_load(const std::string& path);

    // helper: compute urgency score
    static double default_urgency(const Task& t);

private:
    TaskRepository m_repo;
    TagManager m_tags;
    Scheduler m_sched;
    Persistence m_persist;
};

} // namespace stm
