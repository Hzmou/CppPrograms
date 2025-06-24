

/*
    * This is main app.cpp file that uses truck and order classes to read data from a file and process it.
    * It reads truck and order data from a file, processes it, and displays the results.

*/

#include "Truck.h"
#include "Order.h"
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

string trim(const std::string &str);
void displayOrders(const string &truckCity, stack<Order> orders); // function prototype to dispplay order information in a truck.

int main()
{

    Truck truck1("XYTQ23", "Portland");
    Truck truck2("ABCD12", "Bangor");
    Truck truck3("EFGH34", "Lewiston");

    vector<Order> pendingOrder; // vector to hold pending orders that cannot be added to the truck.

    ifstream input("TodayOrders.txt"); // open the file for reading orders.

    if (!input)
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string customer, street, city;

    // read each line from the file and parse the order information.

    while (getline(input, customer))
    {

        getline(input, street);
        getline(input, city);
        city = trim(city); // trim any leading or trailing whitespace from the city name

        int numRefrigerators;
        input >> numRefrigerators;
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Order order(customer, street, city, numRefrigerators);

       // cout << "Processing order for: " << order.getCustomer() << endl;
        if ((order.getCity()) == truck1.getCity())
        {

            if (!truck1.addOrder(order))
            {
                pendingOrder.push_back(order);
            }
        }
        else if ((order.getCity()) == truck2.getCity())
        {

            if (!truck2.addOrder(order))
            {
                pendingOrder.push_back(order);
            }
        }
        else if (order.getCity() == truck3.getCity())
        {

            if (!truck3.addOrder(order))
            {
                pendingOrder.push_back(order);
            }
        }
        else
        {
            cout << "Invalid city: " << order.getCity() << endl;
        }

        // Display pending orders
        if (!pendingOrder.empty())
        {
            cout << "Pending orders:" << endl;
            for (const auto &ord : pendingOrder)
            {
                cout << " - " << ord.getCustomer() << " (" << order.getCity() << ")" << endl;
            }
        }
    }

      displayOrders(truck1.getCity(), truck1.getOrders());
    // displayOrders(truck2.getCity(), truck2.getOrders());
    // displayOrders(truck3.getCity(), truck3.getOrders());
    input.close(); // close the file after reading all orders.
}

void displayOrders(const std::string &truckCity, std::stack<Order> orders)
{
    std::cout << "Orders to " << truckCity << std::endl;
    std::cout << std::left << std::setw(25) << "Customer"
              << std::setw(25) << "Street Address"
              << std::setw(15) << "Refrigerators" << std::endl;

    if (orders.empty())
    {
        std::cout << "  No orders." << std::endl << std::endl;
        return;
    }

    while (!orders.empty())
    {
        Order order = orders.top();
        orders.pop();
        std::cout << std::left << std::setw(25) << order.getCustomer()
                  << std::setw(25) << order.getStreet()
                  << std::setw(15) << order.getNumRefrigerators()
                  << std::endl;
    }
    std::cout << std::endl;
}
// Add this function at the top of your file


std::string trim(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}