

#include "Order.h"
#include "Truck.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



void display(Truck truck); // function to display truck information. 


int main(){

    Truck portlandTruck("Portland", "PL-1234");
    Truck lewistonTruck("Lewiston", "LW-5678");
    Truck bangorTruck("Bangor", "BG-9012");

    ifstream input1;
    ifstream input2;

    input1.open("TodayOrders.txt");
    input2.open("TodayOrders2.txt");    

    if (!input1.is_open() || !input2.is_open()) {
        cout << "Error opening input files." << endl;
        return 1;
    }   

    

}