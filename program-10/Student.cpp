#include "Student.h"

Student::Student() : m_credits {0}
{
}
// invalid credits set to 0
Student::Student (std::string id, std::string name, std::string major, int credits) : 
	m_identification{id}, m_name {name}, m_major {major}, m_credits {credits}
{	if (m_credits < 0)
		m_credits = 0;
}

Student::~Student()
{
}

// accessors
std::string Student::getIdentification() const
{	return m_identification;
}
std::string Student::getName() const
{	return m_name;
}
std::string Student::getMajor() const
{	return m_major;
}
int Student::getCredits() const
{	return m_credits;
}
// mutators
void Student::setIdentification(std::string id)
{	m_identification = id;
}
void Student::setName(std::string name)
{	m_name = name;
}
void Student::setMajor(std::string major)
{	m_major = major;
}
// invalid credits set to 0
void Student::setCredits (int credits)
{	m_credits = credits;
	if (m_credits < 0)
		m_credits = 0;
}

std::string Student::toString () const
{	return m_identification + " " + m_name + " " + m_major + " " + std::to_string(m_credits);
}

