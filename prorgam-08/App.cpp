

#include "Order.h"
#include "Truck.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

void display(const Truck &truck);

int main()
{

    // declaring 3 trucks objects with different license cities. Portland, Lewiston, and Bangor.

    Truck truck1("ABC123", "Portland");
    Truck truck2("XYZ789", "Lewiston");
    Truck truck3("LMN456", "Bangor");

   ifstream input1("TodayOrders.txt");
   ifstream input2("TodayOrders2.txt");

    vector<Order> pendingOrders;

    if (!input1.is_open() || !input2.is_open())
    {
        cerr << "Error opening input files." << endl;
        return 1;
    }

    auto processOrders = [&](ifstream& infile)
    {
        string customer, address, city;
        int numRefrigerators;

        while (getline(infile, customer))
        {

            getline(infile, address);
            getline(infile, city);
            infile >> numRefrigerators;
            infile.ignore(); // Ignore the newline character after the integer

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
    };

    processOrders(input1);
    processOrders(input2);

    input1.close();
    input2.close();
}


void display(const Truck &truck){

}