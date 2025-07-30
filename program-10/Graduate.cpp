
/* Implementation of the Graduate class. */

#include "Graduate.h"
#include <string>

// default constructor.

Graduate::Graduate() : Student(), m_thesisAdvisor(""){}

// Parameterized construnsctor.
Graduate::Graduate(std::string id, std::string name, std::string major, int credits, std::string advisor)
    : Student(id, name, major, credits), m_thesisAdvisor(advisor) {}


// destructor
Graduate::~Graduate() {}

// accessor for thesis advisor
std::string Graduate::getThesisAdvisor() const{

  return m_thesisAdvisor;
}

// setter for thesis advisor.

void Graduate::setThesisAdvisor(std::string advisor) {
    m_thesisAdvisor = advisor;
}

// string representation adds data for thesis advisor.
std::string Graduate::toString() const{

    return Student::toString() + " The Thesis Advisor is: " + m_thesisAdvisor;
}

/* CreditsNeeded() function for the Graduate class, a Graduate student needs 40
   * credits to graduate. 
*/

int Graduate::creditsNeeded() const{
    int needed = 40 - getCredits();
    if( needed > 0 ){
        return needed;
     }else{
        return 0; // No more credits needed to graduate.
    } 
    
}