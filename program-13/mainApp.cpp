#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void readData(string fileName, map<string, vector<string>> &dataMap);

int main()
{

    map<string, vector<string>> stateMap;
    
   

    // Read data from file into map
    readData("States.txt", stateMap);

    // Display the data to verify it was read correctly
    cout << "State data loaded. Total states: " << stateMap.size() << endl
         << endl;

    // Display a few examples
    for (auto &pair : stateMap)
    {
        cout << "State: " << pair.first << endl;
        cout << "  Flower: " << pair.second[0] << endl;
        cout << "  Tree: " << pair.second[1] << endl;
        cout << "  Bird: " << pair.second[2] << endl;
        cout << endl;

        // Only show first 3 states as example
        static int count = 0;
        if (++count >= 3)
            break;
    }

    return 0;
}

void readData(string filename, map<string, vector<string>> &dataMap){

    

string line;   /* string that represents the current line that is being read. */
string currentState;  /* String of the current state we are reading its data. */
vector<string> stateData; /* vector that hold the */
int lineCount = 0;  //this keep track of how many lines on the file, 
                    // it helps us identify the line that has a state name from the state data. 

int lineInGroup = 0; // Track position within each 4-line group



ifstream inputFile(filename);

    // detect errors if the file is not opened correctly. 


    if(!inputFile.is_open()){

        cerr << "Error opening file: " << filename << endl;
        return;
    }



    while(getline(inputFile, line)){

     // increase the line count now:

     lineCount++;
     lineInGroup = (lineCount-1) % 4; 



         



    }















}

    
