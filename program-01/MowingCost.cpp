
/*
  * This is a simple C++ program that calculate the cost of mowing a lawn with 
  
*/

#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;








int main(){


const int surface_per_gallon = 50000;
const double gascost_per_gallon = 3.29;
const int laborCharge = 35;
const double driveway_width =2.5;


char firstName;
string lastName;
int yardLength, yardWidth;
int houseLength, houseWidth;
int poolLength, poolWidth;
int driveWayLength;
double yardArea;
double houseArea;
double poolArea;
double driveWayArea;

double grassLawn;
double numberOfGallons;
double gasCost;
double customerCharge;




cout << "Enter the first letter of your First Name: ";
cin >> firstName;

cout << "Enter your Last Name: ";
cin >> lastName;

cout << "Enter Yard Length and Width: ";
cin >> yardLength;
cin >> yardWidth;

cout << "Enter House length and width: ";
cin >> houseLength;
cin >> houseWidth;


cout << "Enter Pool length and width: ";
cin >> poolLength;
cin >> poolWidth;

cout << "Enter Driveway length: ";
cin >> driveWayLength;


// now doing the calculations for the Mowing cost. 


yardArea = yardLength * yardWidth;
poolArea = poolLength * poolWidth;
houseArea = houseLength * houseWidth;
driveWayArea = driveway_width * driveWayLength;
grassLawn = yardArea - (poolArea + houseArea+driveway_width+driveWayArea);

// calculate the number of Gallons. 

numberOfGallons = grassLawn / surface_per_gallon;

// calculate the Gas Cost. 

gasCost = numberOfGallons * gasCost;
customerCharge = gasCost + laborCharge;

// Now output the report to show the infromation about the cost. 

cout << "Lawn Mowing Report for customer: " << firstName << " " << lastName << endl << endl;


    cout << fixed << setprecision(2);
    cout << setw(30) << "Lawn area(Sq Ft):" << left << grassLawn << endl;
    cout << setw(30) << "Number of gallons:" << numberOfGallons << endl;
    cout << setw(30) << "Gas cost per gallon:"  << gasCost << endl;
    cout << setw(30) << "Gas cost:"  << gascost_per_gallon << endl;
    cout << setw(30) << "Labor cost:"  << laborCharge << endl;
    cout << setw(30) << "Customer charge:" << customerCharge << endl;










}