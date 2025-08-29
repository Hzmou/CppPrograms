

#include "FeetInches.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// function prototype for computing the footage needed.

double computeFootage(const FeetInches &length, const FeetInches &width, const FeetInches &height);

int main()
{

    const double gallonPaint = 31.75;
    const double gallonPerSqaure = 400;

    // the logic of the program starts here,
    // we prompt the user to enter the number of rooms.

    int numRooms;
    cout << "Enter number of rooms: ";
    cin >> numRooms;
    cin.ignore();

    cout << fixed << setprecision(1);

    for (int i = 0; i < numRooms; ++i)
    {

        string roomName, color;
        cout << "\nEnter room name: ";
        getline(cin, roomName);
        cout << "Enter paint color: ";
        getline(cin, color);

        FeetInches length, width, height;
        cout << "Enter length (feet inches): ";
        cin >> length;
        cout << "Enter width (feet inches): ";
        cin >> width;
        cout << "Enter height (feet inches): ";
        cin >> height;
        cin.ignore();

        // doing calculations to ouput the final report. 

        double sqaureFootage = computeFootage(length, width, height);
        double cansNeeded = sqaureFootage / gallonPerSqaure;
        int wholeCans = static_cast<int>(ceil(cansNeeded));
        double totalCost =  wholeCans * gallonPaint;

        // output the report of all the calculations. 
        cout << fixed << setprecision(1);
        cout << "\nRoom: " << roomName << endl;
        cout << "Color: " << color << endl;
        cout << "Square Footage: " << sqaureFootage << endl;
        cout << "Actual Paint Cans Needed: " << cansNeeded << endl;
        cout << "Whole Cans to Purchase: " << wholeCans << endl;

        cout << setprecision(2);
        cout << "Paint Cost:    $" << totalCost << endl;
    }

    return 0;
}

// implementing the function to compute the footage.

double computeFootage(const FeetInches &length, const FeetInches &width, const FeetInches &height)
{

    double l = static_cast<double>(length); // includes feet and inches
    double w = static_cast<double>(width);
    double h = static_cast<double>(height);

    // Four walls: 2*(length * height) + 2*(width * height)
    return 2 * (l * h) + 2 * (w * h);
}