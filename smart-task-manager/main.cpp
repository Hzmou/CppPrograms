


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Application.hpp"

// Minimal stub implementations to let the app compile once you add .cpp files.
// You will implement the real logic in corresponding .cpp files.

namespace stm {

// ---- Application stub ----
Application::Application()
    : m_sched(&Application::default_urgency) {}

int Application::run() {
    std::cout << "Smart Task Manager (CLI)\n";
    std::cout << "Type 'help' for commands, 'exit' to quit." << std::endl;

    std::string line;
    while (std::cout << "\n> " && std::getline(std::cin, line)) {
        if (line == "exit") break;
        if (line == "help") {
            std::cout << "Commands:\n"
                      << "  project add <name>\n"
                      << "  user add <username> <display>\n"
                      << "  task add <project> <title>\n"
                      << "  task list [--project p|--tag t|--user u]\n"
                      << "  task done <id>\n"
                      << "  schedule next\n"
                      << "  save <path>\n"
                      << "  load <path>\n"
                      << "  exit\n";
            continue;
        }

        // naive parsing just to route to handlers; you can replace with proper parser
        std::istringstream iss(line);
        std::string cmd; iss >> cmd;
        if (cmd == "project") {
            std::string sub; iss >> sub;
            if (sub == "add") {
                std::string name; std::getline(iss, name);
                if (!name.empty() && name.front() == ' ') name.erase(0,1);
                handle_project_add(name);
            }
        } else if (cmd == "user") {
            std::string sub; iss >> sub;
            if (sub == "add") {
                std::string username, display; iss >> username; std::getline(iss, display);
                if (!display.empty() && display.front() == ' ') display.erase(0,1);
                handle_user_add(username, display);
            }
        } else if (cmd == "task") {
            std::string sub; iss >> sub;
            if (sub == "add") {
                std::string project; std::string title;
                iss >> project; std::getline(iss, title);
                if (!title.empty() && title.front() == ' ') title.erase(0,1);
                handle_task_add(project, title);
            } else if (sub == "list") {
                std::string opt, val; iss >> opt >> val;
                handle_task_list(opt, val);
            } else if (sub == "done") {
                int id; if (iss >> id) handle_task_done(id);
            }
        } else if (cmd == "schedule") {
            std::string sub; iss >> sub;
            if (sub == "next") handle_schedule_next();
        } else if (cmd == "save") {
            std::string path; iss >> path; handle_save(path);
        } else if (cmd == "load") {
            std::string path; iss >> path; handle_load(path);
        } else {
            std::cout << "Unknown command. Type 'help'." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;
    return 0;
}

// ---- Placeholder handlers (no-op / simple prints) ----
void Application::handle_project_add(const std::string& name) {
    std::cout << "[stub] project add: '" << name << "'" << std::endl;
}

void Application::handle_user_add(const std::string& username, const std::string& display) {
    std::cout << "[stub] user add: '" << username << "' display='" << display << "'" << std::endl;
}

void Application::handle_task_add(const std::string& project, const std::string& title) {
    std::cout << "[stub] task add: project='" << project << "' title='" << title << "'" << std::endl;
}

void Application::handle_task_done(int id) {
    std::cout << "[stub] task done: id=" << id << std::endl;
}

void Application::handle_task_list(const std::string& filter_kind, const std::string& filter_value) {
    std::cout << "[stub] task list: filter_kind='" << filter_kind << "' value='" << filter_value << "'" << std::endl;
}

void Application::handle_schedule_next() {
    std::cout << "[stub] schedule next" << std::endl;
}

void Application::handle_save(const std::string& path) {
    std::cout << "[stub] save to '" << path << "'" << std::endl;
}

void Application::handle_load(const std::string& path) {
    std::cout << "[stub] load from '" << path << "'" << std::endl;
}

// ---- Default urgency (very simple) ----
double Application::default_urgency(const Task& /*t*/) {
    // TODO: compute based on due date, status, estimate.
    return 0.0; // placeholder
}

} // namespace stm

// ---- Program entry point ----
int main() {
    stm::Application app;
    return app.run();
}
