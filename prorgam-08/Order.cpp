#include "Order.h"

Order::Order() : m_numRefrigerators {0}
{	// std::string default constructor called on std::string members
	// initializing them to empty std::string ""
}
	
Order::Order(std::string customer, std::string street, std::string city, int refrig)
{	m_customer = customer;
	m_street = street;
	m_city = city;
	m_numRefrigerators = refrig;		
}

// accessors and mutators
std::string Order::getCustomer() const
{	return m_customer;
}
void Order::setCustomer(std::string customer) 
{	m_customer = customer;
}
std::string Order::getStreet() const
{	return m_street;
}
void Order::setStreet(std::string street) 
{	m_street = street;
}
std::string Order::getCity() 
{	return m_city;
}
void Order::setCity(std::string city) 
{	m_city = city;
}
int Order::getNumRefrigerators() const
{	return m_numRefrigerators;
}
void Order::setNumRefrigerators(int numRefrigerators) 
{	m_numRefrigerators = numRefrigerators;
}
