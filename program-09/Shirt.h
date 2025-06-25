#pragma once
#include <string>

class Shirt
{
public:
	Shirt();					// empty shirt
	Shirt (std::string size, std::string color);

	// accessors and mutators
	std::string getSize() const;
	std::string getColor() const;
	void setSize (std::string s);
	void setColor (std::string c);

	// return string representation 
	std::string toString () const;

	// return retail price
	double retailPrice () const;
private:
	std::string m_size;			// shirt size
	std::string m_color;		// shirt color
};


