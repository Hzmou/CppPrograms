

/* Main application of this program using
the template we defined earlier. */

#include "EmptyCollectionException.h"
#include "TBag.h"
#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{

    vector<string> Employees; // vector to hold the name of the employees.
    Bag<string> nameBag;      // name Bag using the template bag from TBag.h

    // reading the names from the Bangor store
    // add them to the Employees vector of strings.

   
    string bangorFile, brewerFile, line;

    cout << "Enter first store name: ";
    getline(cin,bangorFile);

    ifstream bangorInput(bangorFile);

    // check if we can open the file.

    if (!bangorInput)
    {
        cerr << "Error opening file: " << bangorFile << endl;
        return 1;
    }

    while (getline(bangorInput, line))
    {

        Employees.push_back(line);
        nameBag.insert(line);
    }

    bangorInput.close();

    // read the name of the brewer store.
    std::cout << "Enter second store name: ";
    getline(cin, brewerFile);
    ifstream brewerInput(brewerFile);

    if (!brewerInput)
    {

        cerr << "Error opening file: " << brewerFile << endl;
        return 1;
    }

    while (getline(brewerInput, line))
    {
        if (find(Employees.begin(), Employees.end(), line) == Employees.end())
        {

            Employees.push_back(line);
            nameBag.insert(line);
        }
    }

    brewerInput.close();

    sort(Employees.begin(), Employees.end());

    try
    {
        Bag<string> EmptyBag;
        EmptyBag.remove();
    }

    catch (const EmptyCollectionException &e)
    {

        cout << "caught Exceptio: " << e.what() << endl;
    }

    // making secret santa assignments.

    cout << "\nName\t\tGiftee" << endl;

    for (const auto &employee : Employees)
    {

        string giftee;

        // Special case: if only one name left and it's the same as employee

        if (nameBag.size() == 1)
        {

            try
            {

                string lastPerson = nameBag.remove();
                if (lastPerson == employee)
                {

                    giftee = employee;
                }
                else
                {

                    giftee = lastPerson;
                }
            }
            catch (const EmptyCollectionException &e)
            {

                cerr << e.what() << endl;
            }
        }
        else
        {

            // draw a name, repaer a draw if they draw their own name.
            try
            {
                giftee = nameBag.remove();

                while (giftee == employee && nameBag.size() > 0)
                {

                    nameBag.insert(giftee); // put it back in the bag.

                    giftee = nameBag.remove();
                }
            }
            catch (const EmptyCollectionException &e)
            {
                cerr << e.what() << endl;
            }
        }

        cout << employee << "\t\t" << giftee << endl;
    }
}