

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

vector<Order> readFile(string fileName, Truck& truck); // function prototype to read orders from a file and process them.
string trim(const std::string &str); // function prototype to trim leading and trailing whitespace from a string.
void displayOrders(const string &truckCity, stack<Order> orders); // function prototype to dispplay order information in a truck.

int main()
{

    Truck truck1("XYTQ23", "Portland"); // create a truck object for Portland.
    Truck truck2("ABCD12", "Bangor");  // create a truck object for Bangor.
    Truck truck3("EFGH34", "Lewiston"); // create a truck object for Lewiston.

    vector<Order> pendingOrder; // vector to hold pending orders that cannot be added to the truck.

      string fileName;

      pendingOrder = readFile("TodayOrders.txt", truck1); // read orders from file for truck1.
      pendingOrder = readFile("TodayOrders2.txt", truck1); // read orders from file for truck2.
      pendingOrder = readFile("TodayOrders.txt", truck2);
      pendingOrder = readFile("TodayOrders2.txt", truck2); // read orders from file for truck3.
      pendingOrder = readFile("TodayOrders.txt", truck3);
      pendingOrder = readFile("TodayOrders2.txt", truck3); // read orders from file

      displayOrders(truck1.getCity(), truck1.getOrders());
      displayOrders(truck2.getCity(), truck2.getOrders());
      displayOrders(truck3.getCity(), truck3.getOrders());
      
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



/*
   * Function to read orders from a file and add them to the truck.
 */

vector<Order> readFile(string fileName, Truck& truck){

    vector<Order> pendingOrders;

    ifstream input(fileName);

    if (!input) {
        cerr << "Error opening file." << endl;
        return pendingOrders; // return empty vector if file cannot be opened
    }
    string customer, street, city;

   while(getline(input,customer)){

   
    
      getline(input, street);      // Read street
    getline(input, city);        // Read city
    city = trim(city);

    int numRefrigerators;
    input >> numRefrigerators;
    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Order order(customer, street, city, numRefrigerators);

       // cout << "Processing order for: " << order.getCustomer() << endl;
        if ((order.getCity()) == truck.getCity())
        {

            if (!truck.addOrder(order))
            {
                pendingOrders.push_back(order);
            }
        }
        else if ((order.getCity()) == truck.getCity())
        {

            if (!truck.addOrder(order))
            {
                pendingOrders.push_back(order);
            }
        }
        else if (order.getCity() == truck.getCity())
        {

            if (!truck.addOrder(order))
            {
                pendingOrders.push_back(order);
            }
        }
        else
        {
            cout << "Invalid city: " << order.getCity() << endl;
        }

        // Display pending orders
        if (!pendingOrders.empty())
        {
            cout << "Pending orders:" << endl;
            for (const auto &ord : pendingOrders)
            {
                cout << " - " << ord.getCustomer() << " (" << order.getCity() << ")" << endl;\
            }
        }
    }


    input.close(); // close the file after reading all orders.
    return pendingOrders; // return the vector of pending orders

   }

