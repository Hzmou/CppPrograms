/*
 * C++ Program to read state data from a file into a map and allow user
 * to search for state information.
 * Each state has a name followed by three lines of data (flower, tree, bird)
 * Author: Hamza Zm
 * Date: November 2025
 * C++14 Standard - PS: commits have all the edit updates on this program.
 */

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

/* Function declarations */

void readData(string fileName, map<string, vector<string>> &dataMap);
void displayData(map<string, vector<string>> &dataMap);
void searchState(map<string, vector<string>> &dataMap);
void searchByData(map<string, vector<string>> &dataMap);

int main()
{

    map<string, vector<string>> stateMap; /* Map that holds state data.*/

    // Read data from file into map
    readData("States.txt", stateMap);

    // Display the data to verify it was read correctly
    cout << "State data loaded. Total states: " << stateMap.size() << endl
         << endl;

    displayData(stateMap); // Display all state data
    searchState(stateMap); // Search for specific state data
    searchByData(stateMap);

    return 0;
}

/*
 * Function to read state data from a file and store it in a map.
 * Each state has a name followed by three lines of data (flower, tree, bird)
 * Parameters:
 *   filename - the name of the file to read from
 *   dataMap - the map to store the state data
 */
void readData(string filename, map<string, vector<string>> &dataMap)
{

    string line;              /* string that represents the current line that is being read. */
    string currentState;      /* String of the current state we are reading its data. */
    vector<string> stateData; /* vector that hold the */
    int lineCount = 0;        // this keep track of how many lines on the file,
                              //  it helps us identify the line that has a state name from the state data.

    int lineInGroup = 0; // Track position within each 4-line group

    ifstream inputFile(filename);

    // detect errors if the file is not opened correctly.

    if (!inputFile.is_open())
    {

        cerr << "Error opening file: " << filename << endl;
        return;
    }

    while (getline(inputFile, line))
    {
        // Remove carriage return if present (for Windows line endings)
        if (!line.empty() && line.back() == '\r')
        {
            line.pop_back();
        }

        // increase the line count now:

        lineCount++;
        lineInGroup = (lineCount - 1) % 4;

        if (lineInGroup == 0)
        {

            // this is a state name:

            currentState = line;
            // dataMap[currentState];

            // cout << "state name: " << currentState << endl;

            // make sure to clear the vector
            stateData.clear();
        }
        else
        {
            // this line is a data about the state, this data needs to go into the vector.

            stateData.push_back(line);

            // if we read data about the state in the 3 lines after the currentState we need to add that vector to our map.
            if (stateData.size() == 3)
            {

                dataMap[currentState] = stateData;
            }
        }
    }

    cout << "Total lines read: " << lineCount << endl;
    cout << "Map size after reading: " << dataMap.size() << endl;

    inputFile.close();
}

void displayData(map<string, vector<string>> &dataMap)
{
    // Set column widths
    const int col0 = 20; // State name
    const int col1 = 25; // Flower
    const int col2 = 30; // Tree
    const int col3 = 30; // Bird

    for (const auto &pair : dataMap)
    {
        // Display the state name (left-aligned) followed by data (right-aligned)
        if (pair.second.size() >= 3)
        {
            cout << left << setw(col0) << pair.first      // State name
                 << right << setw(col1) << pair.second[0] // Flower
                 << " " << setw(col2) << pair.second[1]   // Tree
                 << " " << setw(col3) << pair.second[2]   // Bird
                 << endl;
        }
    }
}

/*
 * Function to search for a state by name and display its information.
 * Displays flower, tree, and bird for the state if found.
 */

void searchState(map<string, vector<string>> &dataMap)
{

    string stateName;

    cout << "Enter a state Name to view its information: (q to quit) ";
    getline(cin, stateName);

    while (stateName != "q")
    {

        auto it = dataMap.find(stateName);

        if (it != dataMap.end())
        {
            // State found - display its information
            cout << "Flower:" << right << setw(35) << it->second[0] << endl;
            cout << "Tree:" << right << setw(37) << it->second[1] << endl;
            cout << "Bird:" << right << setw(37) << it->second[2] << endl;
        }
        else
        {
            cout << stateName << " is not found." << endl;
        }

        cout << "Enter a state Name to view its information: (q to quit) ";
        getline(cin, stateName);
    }
}

/*
 * This function searches within each category of the and displays the states
 * that have that flower, tree or bird.
 */

void searchByData(map<string, vector<string>> &dataMap)
{

    string choice;
    string searchTerm;

    while (true)
    {
        cout << "Search by flower, tree, bird (quit to end): ";
        getline(cin, choice);

        if (choice == "quit")
            break;

        // Validate choice
        if (choice != "flower" && choice != "tree" && choice != "bird")
        {
            cout << choice << " is not a valid choice" << endl;
            continue;
        }

        // Determine which index to search (0=flower, 1=tree, 2=bird)
        int searchIndex;
        string itemType;
        if (choice == "flower")
        {
            searchIndex = 0;
            itemType = "flower";
        }
        else if (choice == "tree")
        {
            searchIndex = 1;
            itemType = "tree";
        }
        else
        {
            searchIndex = 2;
            itemType = "bird";
        }

        cout << "Enter part of a " << itemType << " name (quit to end): ";
        getline(cin, searchTerm);

        if (searchTerm == "quit")
            break;

        int count = 0;

        // Search for matches
        for (const auto &pair : dataMap)
        {
            // Case-insensitive partial match
            string itemName = pair.second[searchIndex];
            string itemLower = itemName;
            string searchLower = searchTerm;

            // Convert to lowercase for comparison
            for (auto &c : itemLower)
                c = tolower(c);
            for (auto &c : searchLower)
                c = tolower(c);

            if (itemLower.find(searchLower) != string::npos)
            {
                cout << left << setw(20) << pair.first
                     << itemName << endl;
                count++;
            }
        }

        // Display count with correct grammar
        if (count == 1)
        {
            cout << "There is " << count << " match on " << searchTerm << endl;
        }
        else
        {
            cout << "There are " << count << " matches on " << searchTerm << endl;
        }

        cout << endl;
    }
}
