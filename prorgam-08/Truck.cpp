#include "Truck.h"

// empty truck with no orders
Truck::Truck ()	: m_totalRefrigerators {0}				
{	// string default constructors called for license and city
	// C++ stack constructor called for orders
}

// user passes in license and city for empty truck with no orders
Truck::Truck(std::string license, std::string city) : m_license {license}, 
		m_city {city}, m_totalRefrigerators {0}
{	m_license = license;
	m_city = city;
	// C++ stack constructor called for orders
}

// accessors and mutators
std::string Truck::getLicense() const
{	return m_license;
}
void Truck::setLicense(std::string license)
{	m_license = license;
}
std::string Truck::getCity() const
{	return m_city;
}
void Truck::setCity(std::string city)
{	m_city = city;
}
std::stack<Order> Truck::getOrders() const
{	return m_orders;
}
void Truck::setOrders(std::stack<Order> orders)
{	// C++ stack class does a deep assignment
	m_orders = orders;
}

// empty status
bool Truck::isFull () const
{	// compare total refrigerators to constant MAX brought in from header file
	return m_totalRefrigerators == MAX;
}

// add an order if possible, return success status
bool Truck::addOrder (Order order)
{	// add the order to the truck, update total refrigerators, return true if success
	// return false if order does not fit
	
// checking if this order does not exceed the MAX capacity. 

if(m_totalRefrigerators + order.getNumRefrigerators() > MAX){
   
	return false; // order exceeds capacity. 
}

// add the order to the truck 

m_orders.push(order);
//update total refrigerators.
m_totalRefrigerators += order.getNumRefrigerators();
return true;

}

