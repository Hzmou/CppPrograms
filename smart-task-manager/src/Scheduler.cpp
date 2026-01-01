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

    void Scheduler::clear(){

        while(!m_pq.empty()){
            m_pq.pop();
        }   

    }


}