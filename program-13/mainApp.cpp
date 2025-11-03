#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


void readData(string &fileName, map<string , vector<string>>& dataMap);


int main(){

    map<string, vector<string>> stateMap;
    string filename = "stateData.txt";
    
    // Read data from file into map
    readData(filename, stateMap);
    
    // Display the data to verify it was read correctly
    cout << "State data loaded. Total states: " << stateMap.size() << endl << endl;
    
    // Display a few examples
    for(auto& pair : stateMap) {
        cout << "State: " << pair.first << endl;
        cout << "  Flower: " << pair.second[0] << endl;
        cout << "  Tree: " << pair.second[1] << endl;
        cout << "  Bird: " << pair.second[2] << endl;
        cout << endl;
        
        // Only show first 3 states as example
        static int count = 0;
        if(++count >= 3) break;
    }
    
    return 0;

}


void readData(string &fileName, map<string , vector<string>>& dataMap){
    

    ifstream inputFile(fileName);
    // Check if the file was opened successfully
    if(!inputFile.is_open()){

        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    string line;
    string currentState;
    vector<string> stateData;
    
    while(getline(inputFile, line)) {
        // If we have collected 3 data items for the previous state, store it
        if(stateData.size() == 3) {
            dataMap[currentState] = stateData;
            stateData.clear();
        }
        
        // If stateData is empty, this line is a state name
        if(stateData.empty()) {
            currentState = line;
        } else {
            // This is data for the current state (flower, tree, or bird)
            stateData.push_back(line);
        }
    }
    
    // Don't forget to add the last state's data
    if(stateData.size() == 3) {
        dataMap[currentState] = stateData;
    }
    
    inputFile.close();


}
