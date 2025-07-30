// This class models a graduate student
#pragma once
#include "Student.h"

class Graduate : public Student
{
public:
	Graduate();
	Graduate (std::string id, std::string name, std::string major, int credits, std::string advisor);
	~Graduate();

	//accessor
	std::string getThesisAdvisor() const;
	//mutator
	void setThesisAdvisor(std::string advisor);

	// string representation adds data for thesis advisor
	std::string toString () const;

	// return credits needed to graduate with 40 credits
	int creditsNeeded() const;
	
// attributed of the class. 
private:
	std::string m_thesisAdvisor;			// name of thesis advisor
};


