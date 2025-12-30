/* Impelementation of the Task.hpp class*/

/*
 *  Represents a single work item (e.g., assignment or feature). Stores identity, title/description, due date,
 *  estimate, status, owning project, optional assignee, and a set of tags.
 *  Provides basic tag operations.
 */

#include "Task.hpp"
#include <algorithm>
#include <utility>

namespace stm
{

    /* Constructor public*/
    Task::Task(int id, std::string title)
        : m_id(id), m_title(std::move(title)) {}

    // getters and setters for the class.

    // getter for id.

    int Task::id() const noexcept
    {
        return m_id;
    }

    // getter for title.
    const std::string &Task::title() const noexcept
    {

        return m_title;
    }

    // setter for title.
    void Task::set_title(std::string t)
    {

        m_title = std::move(t);
    }

    // setter for description.
    void Task::set_description(std::string d){
    m_description = std::move(d);
    }

    // setter for due date.
    void Task::set_due(Date d){
        m_due =d;

    }
    // setter for estimate.
    void Task::set_estimate(Estimate e){
        m_estimate =e;

    }
    // setter for status.
    void Task::set_status(TaskStatus s){
        m_status =s;
    }
  
    // setter for project name.
    void Task::set_project(std::string name){

        m_project = std::move(name);

    }

    void Task::assign_user(std::string username{
        if(username.empty()) m_assignee.reset();
        else m_assignee = std::move(username);
    }

    // getter for description. 

    const std::string& Task::description() const noexcept{
        return m_description;
    }
    

    // getter for due date. 

    std::optional<Date> Task::due() const noexcept{
        return m_due;
    }

    // estimate function. 

    std::optional<Estimate> Task::estimate() const noexcept{

        return m_estimate;
    }


    Tasksatus Task::status() const noexcept{

        return m_status;
    }

    const std::string& Task::project() const noexcept{
        return m_project;
    }
    
    const std::optional<std::string>& Task::assignee() const noexcept{
        return m_assignee;
    }

    // tag operations. 

    bool Task::add_tag(const std::string& tag){
        retrun m_tag.insert(tag).second;

    }

    bool Task::remove_tag(const std::string& tag){

        return m_tags.erase(tag)>0;

    }

    const std::set<std::string& Task::tags() const noexcept{
        return m_tags;
    }
    
    



}  // namespace stm. 