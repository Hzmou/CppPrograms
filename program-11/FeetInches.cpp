

#include "FeetInches.h"
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

    return m_feet == other.m_feet && m_inches == other.m_inches;
 
}

bool FeetInches::operator!=(const FeetInches& other) const
{
    return !(*this == other);
}

bool FeetInches::operator<(const FeetInches& other) const
{
    return (m_feet * 12 + m_inches) < (other.m_feet * 12 + other.m_inches);
}

bool FeetInches::operator<=(const FeetInches& other) const
{
    return *this < other || *this == other;
}

bool FeetInches::operator>(const FeetInches& other) const
{
    return !(*this <= other);
}

bool FeetInches::operator>=(const FeetInches& other) const
{
    return !(*this < other);
}


// math operator function. 

FeetInches FeetInches::operator+(const FeetInches& other) const {

 FeetInches temp(m_feet + other.m_feet, m_inches + other.m_inches);
 temp.simplify();
 return temp;

}

// Incremen operators. 


// add 1 to inches (prefix)
FeetInches FeetInches::operator++(){

    ++m_inches;
    simplify();
    return *this;
}


// add 1 to inches (postfix)
FeetInches FeetInches::operator++(int){

    FeetInches temp = *this;
     m_inches++;
     simplify();
     return temp;
}    

// type conversion operators. 


// return total inches (ex. 2 feet, 1 inch --> 25)

FeetInches::operator int() const {
   
 return m_feet *12 +m_inches;
}


// return units of feet (ex. 2 feet, 6 inches --> 2.5)
FeetInches:: operator double() const{

    return m_feet + m_inches /12.0;

}

//IO operators
	std::ostream& operator<< (std::ostream& os, const FeetInches& object){
     
     os << object.getFeet() << ":" << object.getInches();
     return os;

    }	
    
    // display feet:inches
	std::istream& operator>> (std::istream& is, FeetInches& object){
      int feet , inches;
      is >> feet >> inches;
      object.setFeet(feet);
      object.setInches(inches);
    return is;
      
    }