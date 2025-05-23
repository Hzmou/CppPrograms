
/*
 * This is a basic program in C++ that uses vectors to store and manipulate student grades.
 * and output the results in a table for the entire class. We read the grades from a file,
 * sort them, and then calculate the average, median, and standard deviation and the top 3 grades for
 * the midterm and final.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// function prototypes.
double mean(vector<int> v);                         // function to calculate grades mean.
double stddev(vector<int> v, double mean);          // function to calculate standard deviation.
char letter(int score, double mean, double stddev); // function to calculate letter grade.
void top3(const vector<int> &v);                    // function to calculate top 3 grades for the final and midterm.






int main()
{

    vector<string> codes; // student IDs.
    vector<int> midterm;  // vecotor to store midterm grades.
    vector<int> final;    // vector to store final grades.

    ifstream input;
    input.open("grades.txt"); // open the file grades.txt
    if (!input)
    { // check if the file opened successfully
        cout << "Error opening file." << endl;
        return 1;
    }

     string code;
     int mid, fin;

    // Read each line and store values in the vectors
    while (input >> code >> mid >> fin) {
        codes.push_back(code);
        midterm.push_back(mid);
        final.push_back(fin);
    }

    input.close(); // Close the file after reading
    
   
}
