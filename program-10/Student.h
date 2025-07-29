// Student class is an abstract base class that models a general student at a university
#pragma once
#include <string>

class Student
{
public:
	Student();
	Student (std::string id, std::string name, std::string major, int credits);
	virtual ~Student();

	// accessors
	std::string getIdentification() const;
	std::string getName() const;
	std::string getMajor() const;
	int getCredits() const;
	// mutators
	void setIdentification(std::string id);
	void setName(std::string name);
	void setMajor(std::string major);
	void setCredits (int credits);

	// string reprentation
	virtual std::string toString () const;

	// abstract function that returns number of credits to graduation
	virtual int creditsNeeded() const = 0;

private:
	std::string m_identification;		// student id
	std::string m_name;					// student name
	std::string m_major;				// student major
	int m_credits;						// number of credits
};

