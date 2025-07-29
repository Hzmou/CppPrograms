// Undergraduate models an undergraduate student

#pragma once
#include "Student.h"

class Undergraduate : public Student
{
public:
	Undergraduate();
	Undergraduate (std::string id, std::string name, std::string major, int credits);
	~Undergraduate();

	// return credits needed to graduate with 120 credits
	int creditsNeeded() const;

	// return year in school (First Year, Sophomore, Junior, Senior) based on credits
	std::string yearStatus() const;
};

