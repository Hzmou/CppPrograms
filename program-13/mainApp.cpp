#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void readData(string fileName, map<string, vector<string>>  &dataMap);
void displayData(map<string , vector<string>> &dataMap);

int main()
{

    map<string, vector<string>> stateMap;

    // Read data from file into map
    readData("States.txt", stateMap);

    // Display the data to verify it was read correctly
    cout << "State data loaded. Total states: " << stateMap.size() << endl
         << endl;

     displayData(stateMap);

    return 0;
}

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

   for (const auto &pair : dataMap)
    {
        cout
             << setw(25) << left << pair.first           // State name
             << setw(25) << left << pair.second[0]      // Flower
             << setw(25) << left << pair.second[1]        // Tree
             << setw(20) << left << pair.second[2]        // Bird
             << endl;
      
        

    }


}