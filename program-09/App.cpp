

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

    vector<string> colors = readShirtColors("shirt_colors.txt");

    double totalCost = 0.0;
    char shirtType;

    do
    {

        cout << "Enter shirt type (P for Polo, S for Standard, Q to quit): ";
        cin >> shirtType;

        string size, color, monogram;
        int qty = 0;

        // get the size.

        cout << "Enter shirt size (S, M, L, XL): ";
        cin >> size;

        // convert size to uppercase:

        transform(size.begin(), size.end(), size.begin(), ::toupper);

        // get the color.

        cout << "Enter color ( Black, Blue, Green, Light Blue, Orange, Navy, Pink, Purple, Red, Tan, White ): ";

        getline(cin, color);

        if (shirtType = 'P')
        {

            cout << "Enter text for monogram (1 to 10 characters): ";
            getline(cin, monogram);
        }

        

    } while (shirtType != 'Q' && shirtType != 'q');
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
}
