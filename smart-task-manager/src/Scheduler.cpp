/* Implementation of the Scheduler.hpp class */

/* This class Handles saving and loading the application state
 (projects, users, tasks)*/

#include "Scheduler.hpp"
#include <stdexcept>

namespace stm {

    // constructor that takes an urgency function  

    Scheduler::Scheduler(UrgencyFn fn) 
    : m_urgency(std::move(fn)) {}



 /* Load function for scheduler, this function loads tasks into
  the scheduler's priority queue */

    void Scheduler::load(const std::vector<Task>& tasks){
    

        for(const auto& task : tasks){

            double score = m_urgency(task);
            m_pq.push(Node{score, task});
        }



    }
   

   /* clears all the tasks from the scheduler */
    void Scheduler::clear(){

        while(!m_pq.empty()){
            m_pq.pop();
        }   



    }

  /* checks if the schedule is empty returns true or false.*/
    bool Scheduler::empty() const noexcept{
        return m_pq.empty();
    }


    /* returns the number of tasks in the scheduler. */
    size_t Scheduler::size() const noexcept{
        return m_pq.size(); 
    }

   
    /* returns the most urgent task without removing it from the scheduler .*/
    const Task& Scheduler:: peek() const{
        if (m_pq.empty()){
            throw std:: runtime_error("Scheduler is empty");
        }
        return  m_pq.top().task();
    }

    // removes and returns the most urgent task from the scheduler.

    const Task& Scheduler::pop(){

        if(m_pq.empty()){
            throw std:: runtime_error("Scheduler is empty");

        }
        
        // the most urgent task would be on top of the priority queue

        Task topTask = m_pq.top().task;


         // remove the top task from the priority queue
        m_pq.pop();
        return topTask;
    }


} // namespace stm