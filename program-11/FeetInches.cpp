

#include <FeetInches.h>
#include <iostream>
#include <iostream>

// Default constructor
FeetInches::FeetInches() : m_feet(0), m_inches(0) {}

// Parameterized constructor
FeetInches::FeetInches(int f, int i) : m_feet(f), m_inches(i)
{
    simplify();
}

// Accessors
int FeetInches::getFeet() const
{
    return m_feet;
}

int FeetInches::getInches() const
{
    return m_inches;
}

// setters:

void FeetInches::setFeet(int f)
{
    m_feet = f;
    simplify();
}

void FeetInches::setInches(int i)
{
    m_inches = i;
    simplify();
}

// private method to simplify feet and inches.

void FeetInches::simplify()
{
    if (m_inches >= 12)
    {
        m_feet += m_inches / 12;  // convert excess inches to feet.
        m_inches = m_inches % 12; // keep only the remainder inches.
    }
    else if (m_inches < 0)
    {

        int feetToSubtract = (-m_inches + 11) / 12; // calculate how many feet to subtract
        m_feet -= feetToSubtract;                   // subtract feet
        m_inches += feetToSubtract * 12;            // adjust inches accordingly
    }

    if (m_feet < 0 && m_inches > 0)
    {
        m_feet += 1;
        m_inches -= 12;
    }
}


// relational operators functions. 

bool FeetInches::operator==(const FeetInches& other)const{

}