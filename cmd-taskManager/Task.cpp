

#include "Task.h"
#include <iostream>
#include <iostream>
#include <string>

using namespace std;



//constructor.

Task::Task(int _id, const std::string& desc)
    : id(_id), description(desc), completed(false), dueDate(""), priority(0)
{
}

//getters and setters. 

int Task::getId() const{
    return id;
}

string Task::getDescription() const{
    return description;
}

bool Task::isCompleted() const{

    return completed;
}

void Task::setDescription(const std::string& desc){
    description = desc;
}
void Task::markComplete(){
   completed = true;    

}

void Task::markPending(){
    completed = false;
}

void Task::setDueDate(){

    string input;

    cout << "Enter due date for this task (e.g YYYY-MM-DD): ";

    getline(cin, input);
    if(!input.empty()){
        dueDate = input;
    }

}


void Task::getPriority(){

    cout << "Priority: " << priority << endl;
}







