

#include "Order.h"
#include "Truck.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include<iomanip>
#include <sstream>
using namespace std;

void display(const Truck &truck);


int main()
{

    // declaring 3 trucks objects with different license cities. Portland, Lewiston, and Bangor.

    Truck truck1("ABC123", "Portland");
    Truck truck2("XYZ789", "Lewiston");
    Truck truck3("LMN456", "Bangor");

   ifstream input1;
   input1.open("TodayOrders.txt")
  


    vector<Order> pendingOrders;

    if (!input1 || !input2) {
    std::cerr << "Could not open one or both files.\n";
    return 1;
}
   
   
        string customer, address, city;
        int numRefrigerators;
        string numStr;
        string line;
        

        while (getline(input1, customer) )
        {

            getline(input1, address);
            getline(input1, city);
           
            input1 >> numRefrigerators;
            input1.ignore(); // Ignore the newline character after the integer
            
            
            
            Order order(customer, address, city, numRefrigerators);

            if (city == "Portland")
            {
                if (!truck1.addOrder(order))
                {
                    pendingOrders.push_back(order);
                }
            }
            else if (city == "Lewiston")
            {
                if (!truck2.addOrder(order))
                {
                    pendingOrders.push_back(order);
                }
            }
            else if (city == "Bangor")
            {
                if (!truck3.addOrder(order))
                {
                    pendingOrders.push_back(order);
                }
            }
            else
            {
                pendingOrders.push_back(order);
            }
        }

       
    

    

    input1.close();
    input2.close();

    display(truck1);
    display(truck2);
    display(truck3);
    cout << "Pending Orders:\n";
    if (pendingOrders.empty()) {
        std::cout << "No pending orders.\n";
    } else {
        for (const auto& order : pendingOrders) {
            std::cout << std::left << std::setw(25) << order.getCustomer()
                      << std::setw(20) << order.getStreet()
                      << order.getNumRefrigerators() << '\n';
        }
        std::cout << "--------------------------\n";
    }
}


void display(const Truck &truck)
{
    std::cout << "Truck License: " << truck.getLicense() << "\n";
    std::cout << "Destination City: " << truck.getCity() << "\n";
    std::cout << "Orders in Truck:\n";

    if (truck.getOrders().empty()) {
        std::cout << "No orders in this truck.\n";
        return;
    }

    std::stack<Order> orders = truck.getOrders();
    while (!orders.empty()) {
        Order order = orders.top();
        orders.pop();
        std::cout << std::left << std::setw(25) << order.getCustomer()
                  << std::setw(20) << order.getStreet()
                  << order.getNumRefrigerators() << '\n';
    }
    std::cout << "--------------------------\n";
}