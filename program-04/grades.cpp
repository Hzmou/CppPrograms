
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
#include <cmath>
#include <numeric>

using namespace std;

// function prototypes.
double mean(vector<int> v);                         // function to calculate grades mean.
double stddev(vector<int> v, double mean);          // function to calculate standard deviation.
char letter(int score, double mean, double stddev); // function to calculate letter grade.
void top3(const vector<int> &v);                    // function to calculate top 3 grades for the final and midterm.

double mean(vector<int> v)
{

    if (v.empty())
    {

        return 0.0;
    }

    double sum = accumulate(v.begin(), v.end(), 0.0);
    double mean = sum / v.size();
    return mean;
}
double stddev(vector<int> v, double m)
{
    if (v.empty())
    {

        return 0.0;
    }

    double sumSqauredDiff = 0.0;

    for (int value : v)
    {

        sumSqauredDiff += pow(value - m, 2);
    }

    double stdDev = sqrt(sumSqauredDiff / v.size());
    return stdDev;
}

char letter(int score, double mean, double stddev)
{

    // char letterGrade;

    if (score < mean - 1.5 * stddev)
    {
        return 'E';
    }
    else if (score < mean - 0.5 * stddev)
    {
        return 'D';
    }
    else if (score < mean + 0.5 * stddev)
    {
        return 'C';
    }
    else if (score < mean + 1.5 * stddev)
    {
        return 'B';
    }
    else
    {

        return 'A';
    }
}

void top3(const vector<int> &v)
{

    vector<int> sorted = v;
    int size = sorted.size();
    int i, j;

    // Sort the vector in descending order.
    // use sort() function from the algorithm library.
    // Bubble sort algorithm to sort the vector in descending order

    sort(sorted.begin(), sorted.end(), greater<int>());

    for (int i = 0; i < 3 && i < sorted.size(); ++i)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<string> codes; // student IDs.
    vector<int> midterm;  // vecotor to store midterm grades.
    vector<int> final;    // vector to store final grades.
    // Calculate means and standard deviations

    double meanMid = mean(midterm);
    double meanFin = mean(final);
    double stddevMid = stddev(midterm, meanMid);
    double stddevFin = stddev(final, meanFin);

    ifstream input;
    cout << "enter Input file name: ";
    string fileName;
    cin >> fileName;
    input.open(fileName); // open the file grades.txt
    if (!input)
    { // check if the file opened successfully
        cout << "Error opening file." << endl;
        return 1;
    }

    string code;
    int mid, fin;

    // Read each line and store values in the vectors
    while (input >> code >> mid >> fin)
    {
        codes.push_back(code);
        midterm.push_back(mid);
        final.push_back(fin);
    }

    input.close(); // Close the file after reading

    // Output the data as specified in our assignment instructions.

    cout << "Code     Midterm   Grade    Final   Grade" << endl;
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < codes.size(); ++i)
    {
        cout << left << setw(10) << codes[i] << " " << setw(7) << midterm[i] << " " << setw(5) << letter(midterm[i], meanMid, stddevMid)
             << " " << setw(5) << final[i] << " " << setw(5) << letter(final[i], meanFin, stddevFin)
             << endl;
    }

    top3(midterm);
}
