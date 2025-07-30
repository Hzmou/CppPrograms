

#include "Student.h"
#include "Graduate.h"
#include "Undergraduate.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


// function prototypes.
vector<Student*> readFile(const string& filename);
void display(vector<Student *> students , string studentType);



int main(){

}



/*
 * Function to  read the students data into a vector of Student pointers.
*/

vector<Student*> readFile(const string& filename){

 vector<Student*> students;
 ifstream file(filename);
 string line;

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return students;
    }

while(getline(file, line)){

    istringstream iss(line);
    string type , id , name, major , advisor;
    int credits;

    



} 


}