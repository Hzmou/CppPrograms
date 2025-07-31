#pragma once
#include <ostream>
#include <istream>

class FeetInches
{	
	public:
		FeetInches ();									// feet and inches set to 0
		FeetInches (int f, int i);						// set feet to f and inches to i and simplify													
		
		// accessors and modifiers
		int getFeet() const;
		int getInches() const;
		void setFeet (int f);
		// set inches and simplify
		void setInches (int i);							
		
		// relational operators
		bool operator== (const FeetInches& other) const;	// return true if feet and inch values same
		bool operator!= (const FeetInches& other) const;
		bool operator< (const FeetInches& other) const;		// return total inches less than other total inches
		bool operator<= (const FeetInches& other) const;
		bool operator> (const FeetInches& other) const;		// return total inches more than other total inches
		bool operator>= (const FeetInches& other) const;

		// math operator
		// return object with feet and inches from other and simplify
		FeetInches operator+ (const FeetInches& other) const;	
				
		// increment and decrement operators
		FeetInches operator++ ();					// add 1 to inches (prefix)
		FeetInches operator++ (int);				// add 1 to inches (postfix)
		
		// type conversion
		operator int () const;						// return total inches (ex. 2 feet, 1 inch --> 25)
		operator double () const;					// return units of feet (ex. 2 feet, 6 inches --> 2.5)
	private:
		int m_feet;									// feet 0..
		int m_inches;								// inches 0..11
		void simplify();							// feet and inches set and inches < 12
	};

	//IO operators
	std::ostream& operator<< (std::ostream&, const FeetInches& object);	// display feet:inches
	std::istream& operator>> (std::istream&, FeetInches& object);		// read feet inches

