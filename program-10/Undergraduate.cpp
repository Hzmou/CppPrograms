

/* Undergraduate class implmentation. */

#include "Undergraduate.h"
#include <string>

// default constructor
Undergraduate::Undergraduate() : Student() {}

// parameterized constructor.

Undergraduate::Undergraduate(std::string id, std::string name, std::string major, int credits)
    : Student(id, name, major, credits) {}

// destructor
Undergraduate::~Undergraduate() {}

// defining the creditsNeeded() function that belongs to the Undergraduate class."

int Undergraduate::creditsNeeded() const
{
    int needed = 120 - getCredits();
    if (needed > 0)
    {

        return needed;
    }
    else
    {
        return 0; // no credits needed if already at or above 120
    }
}

// defining the yearStatus() function that belongs to the Undergraduate class.
// returns the year in shool bases on the number of credits the student has earned.

std::string Undergraduate::yearStatus() const
{

    int credits = getCredits();

    if (credits < 30)
    {
        return "First Year";
    }
    else if (credits < 60)
    {
        return "Sophomore";
    }
    else if (credits < 90)
    {
        return "Junior";
    }
    else
    {
        return "Senior";
    }
}