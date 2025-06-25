#include "Shirt.h"

// empty shirt 
Shirt::Shirt()
{	// string default constructor is called setting size and color to ""
}

// parameterized constructor
// if size not in set S, M, L, XL, size set to S
Shirt::Shirt (std::string size, std::string color) :
		m_size (size), m_color (color)
{	if (size != "S" && size != "M" && size != "L" && size != "XL")
		m_size = "S";
}

// accessors and mutators
std::string Shirt::getSize() const
{	return m_size;
}
std::string Shirt::getColor() const
{	return m_color;
}
// if size not in set S, M, L, XL, size set to S
void Shirt::setSize (std::string size)
{	if (size != "S" && size != "M" && size != "L" && size != "XL")
		m_size = "S";
	else
		m_size = size;
}
void Shirt::setColor (std::string c)
{	m_color = c;
}

// string representation
std::string Shirt::toString () const
{	return m_size + " " + m_color;
}

// assign retail prices 
double Shirt::retailPrice () const
{	if (m_size == "S" || m_size == "M")
		return 15.99;
	else if (m_size == "L")
		return 16.99;
	else 
		return 17.99;
}
