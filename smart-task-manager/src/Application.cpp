/* Implementation of the Application.hpp class. */

/* This class is the main CLI application. It runs the main loop and routes
 user commands to handlers.
 */

 #include "Application.hpp"
 #include <iostream>
 #include <sstream>

 namespace stm{


    Application:: Application()
      : m_repo(),
        m_tags(),
        m_sched(m_repo, default_urgency),
        m_persist(m_repo, m_tags){}

      int Application::run(){

        std::cout << "Welcome to the Task Manager CLI!" << std::endl;
        std::string line;
        while (true) {
            std::cout << "> ";
            if (!std::getline(std::cin, line)) {
                break; // EOF or error
            }

            std::istringstream iss(line);
            std::string command;
            iss >> command;

            if (command == "exit") {
                break;
            } else if (command == "project_add") {
                std::string name;
                iss >> name;
                handle_project_add(name);
            } else if (command == "user_add") {
                std::string username, display;
                iss >> username >> display;
                handle_user_add(username, display);
            } else if (command == "task_add") {
                std::string project, title;
                iss >> project;
                std::getline(iss, title);
                handle_task_add(project, title);
            } else if (command == "task_done") {
                int id;
                iss >> id;
                handle_task_done(id);
            } else if (command == "task_list") {
                std::string filter_kind, filter_value;
                iss >> filter_kind >> filter_value;
                handle_task_list(filter_kind, filter_value);
            } else if (command == "schedule_next") {
                handle_schedule_next();
            } else if (command == "save") {
                std::string path;
                iss >> path;
                handle_save(path);
            } else if (command == "load") {
                std::string path;
                iss >> path;
                handle_load(path);
            } else {
                std::cout << "Unknown command: " << command << std::endl;
            }
        }

        std::cout << "Exiting Task Manager CLI. Goodbye!" << std::endl;
        return 0;
        
      }  


      void Application::handle_project_add(std::string const& name){

        std::cout << "Adding Project: " << name << std::endl;

      }

      void Application::handle_user_add(const std::string& username, const std::string& display){
        std::cout << "Adding User" << std::endl;
      }

      void Application::handle_task_add(const std::string& project, const std::string& title){
        std::
      }
     
 }
