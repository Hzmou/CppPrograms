/* Complete implementation of the Application class.*/

/*

  * The top-level CLI application orchestrating repositories, tag management, scheduling,
  * and persistence. Runs the main loop and routes user commands to handlers.


*/

#include "Application.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <chrono>

namespace stm
{

    /*

     * Anonymous (unnamed) namespace: limits these helpers to this translation unit.
     * This prevents symbol collisions and keeps internal utility functions private
     * to this .cpp file (gives them internal linkage).

    */
    namespace
    {

        // trims leading and trailing whitespace from a string.

        static inline std::string trim(const std::string &s)
        {
            auto b = s.find_first_not_of(" \t\n\r");
            if (b == std::string::npos)
                return "";
            auto e = s.find_last_not_of(" \t\n\r");
            return s.substr(b, e - b + 1);
        }

        // Convert TaskStatus enum to a short string for CLI output.
        // Kept here because it's only needed by Application's formatting logic.
        static std::string status_to_string(TaskStatus s)
        {
            switch (s)
            {
            case TaskStatus::Todo:
                return "Todo";
            case TaskStatus::InProgress:
                return "InProgress";
            case TaskStatus::Done:
                return "Done";
            case TaskStatus::Archived:
                return "Archived";
            default:
                return "Unknown";
            }
        }

    } // end of unnamed namespace. 



  // public constructor to intialize values. 

  Application::Application()
        : m_repo(), m_tags(), m_sched(default_urgency) ,m_persist(){}
    
  // main CLI loop. 


  int Application::run(){

   std::cout << "Welcome to the Task Manager CLI!";
   std::string line;

   while(true){
   

    std::cout << "> ";

    if(!std::getline(std::cin , line)){
        break;
    }

    std::istringstream iss (line);
     std::string cmd;

     if (!(iss >> cmd)){
        continue;
     }

     if(cmd == "exit"){
        exit(0);



     }else if(cmd == "help"){
        std::cout << "Commands:\n"
                      << "  project add <name>            Add a project\n"
                      << "  user add <username> <display> Add a user\n"
                      << "  task add <project> <title>    Add a task to a project (title may contain spaces)\n"
                      << "  task list                     List all tasks\n"
                      << "  task list --project <name>    List tasks for a project\n"
                      << "  task list --tag <tag>         List tasks with a tag\n"
                      << "  task list --user <username>   List tasks assigned to a user\n"
                      << "  task done <id>                Mark task as done\n"
                      << "  schedule next                 Show the most urgent next task\n"
                      << "  save <path>                   Save state to file\n"
                      << "  load <path>                   Load state from file\n"
                      << "  help                          Show this help\n"
                      << "  exit                          Quit\n\n"
                      << "Examples:\n"
                      << "  project add Personal\n"
                      << "  user add jdoe \"John Doe\"\n"
                      << "  task add Personal Fix bug in parser\n"
                      << "  task list --project Personal\n";
            continue;

     }
   

     //adding a project. 

     if(cmd == "project"){
        std::string subcmd ; 
        iss>> subcmd;
        if(subcmd == "add"){
            
        }

     }
     

  

    

   }


   




  }
     
}
