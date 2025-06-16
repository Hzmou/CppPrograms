// Truck class models a delivery truck
#pragma once
#include "Order.h"
#include <string>
#include <stack>

constexpr int MAX {6};			// maximum units truck can hold

class Truck
{
public:
	// constructors
	Truck ();					// empty truck with no orders
	Truck (std::string license, std::string city);
	// accessors and mutators
	std::string getLicense() const;
	void setLicense(std::string license);
	std::string getCity() const;
	void setCity(std::string city);
	std::stack<Order> getOrders() const;
	void setOrders(std::stack<Order> orders);
	// empty status
	bool isFull () const;
	// add an order if possible, return success status
	bool addOrder (Order order);
private:
	std::string m_license;		// license number of truck
	std::string m_city;			// destination city for truck
	int m_totalRefrigerators; 	// total number of refrigerators on truck
	std::stack<Order> m_orders;	// stack of orders
};

