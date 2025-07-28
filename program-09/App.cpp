
/* Basic program to practice classes and subclasses. This program claculates the price for a quantity of shirt or Polo shirts.
 * Author: Hamza Zm.
 * Date: 2023-10-01
 * Version: 1.0,    c++14.
 */
#include "Shirt.h"
#include "Poloshirt.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// function prototype to read shirt colors from a file
// into a vector of strings.
vector<string> readShirtColors(const string &filename);

int main()
{

    vector<string> colors = readShirtColors("shirt_colors.txt"); // vector to hold shirt colors.

    double totalCost = 0.0; // variable to hold the total cost of all shirts.
    char shirtType;         // variable to hold the type of shirt (P for Polo, S for Standard, Q to quit).

    /* do,while loop to implement the program logic.*/

    do
    {

        cout << "Enter shirt type (P for Polo, S for Standard, Q to quit): ";
        cin >> shirtType;
        shirtType = toupper(shirtType);

        if (shirtType == 'Q')
        {
            break; // exit the loop if user enters 'Q'.
        }

        string size, color, monogram;
        int qty = 0;

        /* Input a monogram if the shirt is a Polo.*/
        if (shirtType == 'P')
        {
            cin.ignore(); // ignore the newline character left in the input buffer.
            cout << "Enter text for monogram (1 to 10 characters): ";
            getline(cin, monogram);
        }
        else
        {

            monogram = ""; // no monogram for standard shirts
            cin.ignore();  // ignore the newline character left in the input buffer.
        }

        /* get size of shirt or Polo input.*/

        cout << "Enter shirt size (S, M, L, XL): ";
        cin >> size;

        // convert size to uppercase:

        transform(size.begin(), size.end(), size.begin(), ::toupper);

        cin.ignore(); // ignore the newline character left in the input buffer.

        /* get the color input. */

        cout << "Enter color ( Black, Blue, Green, Light Blue, Orange, Navy, Pink, Purple, Red, Tan, White ): ";
        getline(cin, color);

        /* get input for the quantity of product. (short or Polos.). */

        cout << "Enter Quantity (1...10): ";
        cin >> qty;

        /* Calculate the price for Polo and shirt and then output the data. */

        double price = 0.0, cost = 0.0;

        if (shirtType == 'P')
        {

            PoloShirt polo(size, color, monogram); // create a PoloShirt object with the given size, color, and monogram.
            price = polo.retailPrice();
            cost = price * qty;

            /* output all the information about the shirt. */

            cout << left << setw(8) << "Size"
                 << setw(12) << "Color"
                 << setw(12) << "Monogram"
                 << setw(14) << "Retail Price"
                 << setw(10) << "Quantity"
                 << "Cost" << endl;

            cout << left << setw(8) << size
                 << setw(12) << color
                 << setw(12) << monogram
                 << setw(14) << fixed << setprecision(2) << price
                 << setw(10) << qty
                 << fixed << setprecision(2) << cost << endl;
        }
        else
        {

            /* this means our shirt is a standard shirt, we output all the info about our shirt.*/

            Shirt shirt(size, color); // create a Shirt object with the given size and color.
            price = shirt.retailPrice();
            cost = price * qty; // calculate the cost for the quantity of shirts.

            cout << left << setw(8) << "Size"
                 << setw(12) << "Color"
                 << setw(14) << "Retail Price"
                 << setw(10) << "Quantity"
                 << "Cost" << endl;

            cout << left << setw(8) << size
                 << setw(12) << color
                 << setw(14) << fixed << setprecision(2) << price
                 << setw(10) << qty
                 << fixed << setprecision(2) << cost << endl;
        }

        totalCost += cost; // add the cost of the current shirt to the total cost.

        cout << endl;

    } while (shirtType != 'Q' && shirtType != 'q');

    cout << "Total cost of all shirts: $" << fixed << setprecision(2) << totalCost << endl;
    return 0;
}

/*
 *
 */
vector<string> readShirtColors(const string &filename)
{

    vector<string> colors;
    ifstream input(filename);
    string color;

    while (getline(input, color))
    {
        if (!color.empty())
        {
            colors.push_back(color);
        }

        return colors;
    }

    return colors;
}
