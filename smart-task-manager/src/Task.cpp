/* Impelementation of the Task.hpp class*/

/*
 *  Represents a single work item (e.g., assignment or feature). Stores identity, title/description, due date,
 *  estimate, status, owning project, optional assignee, and a set of tags.
 *  Provides basic tag operations.
 */

#include "Task.hpp"
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



}