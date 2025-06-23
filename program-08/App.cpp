

/*
    * This is main app.cpp file that uses truck and order classes to read data from a file and process it.
    * It reads truck and order data from a file, processes it, and displays the results.

*/

#include "Truck.h"
#include "Order.h"
#include<stdio.h>
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
#include<sstream>
#include<iostream>


using namespace std;

void Display(Truck truck); // function prototype to dispplay order information in a truck. 





int main(){

Truck truck1("XYTQ23", "Portland"); 
Truck truck2("ABCD12", "Bangor");
Truck truck3("EFGH34", "Lewiston");


vector<Order> pendingOrder; // vector to hold pending orders that cannot be added to the truck.

ifstream input("TodayOrders.txt"); // open the file for reading orders.

if (!input) {
    cerr << "Error opening file." << endl;
    return 1;
}

string line;



// read each line from the file and parse the order information. 

while (getline(input, line)) {
    istringstream iss(line);
    string customer, street, city;
    int numRefrigerators;
    iss >> customer >> street >> city >> numRefrigerators;
    Order order(customer, street, city, numRefrigerators);
    
    if((order.getCity()) == "Portland")
     {
        truck1.addOrder(order);
        if(truck1.isFull()){
            pendingOrder.push_back(order);  
            
        }
     }else if((order.getCity()) == "Bangor"){
        truck2.addOrder(order);
        if(truck2.isFull()){
            pendingOrder.push_back(order);  
        }
 
    } else if(order.getCity() == "Lewiston"){
        truck3.addOrder(order);
        if(truck3.isFull()){
            pendingOrder.push_back(order);  
        }
    } else {
        cout << "Invalid city: " << order.getCity() << endl;
    }


   // Display pending orders
   if (!pendingOrder.empty()) {
       cout << "Pending orders:" << endl;
       for (const auto& ord : pendingOrder) {
           cout << " - " << ord.getCustomer() << " (" << order.getCity() << ")" << endl;
       }
   }

}

}