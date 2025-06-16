// Order class models one order
#include <string>

#pragma once
class Order
{	
public:
	// constructors
	Order();					// empty order
	Order(std::string customer, std::string street, std::string city, int refrig);
	// accessors and mutators
	std::string getCustomer() const;
	void setCustomer(std::string customer);
	std::string getStreet() const;
	void setStreet(std::string street);
	std::string getCity();
	void setCity(std::string city);
	int getNumRefrigerators() const;
	void setNumRefrigerators(int numRefrigerators);
private:
	std::string m_customer;		// customer name
	std::string m_street;		// street address
	std::string m_city;			// city name
	int m_numRefrigerators;		// number of refrigerators in order
};

