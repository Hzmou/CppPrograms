
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
double mean(vector<int> v);                 // function to calculate grades mean.
double stddev(vector<int> v, double mean);  // function to calculate standard deviation.
char letter(int score, double m, double s); // function to calculate letter grade.
void top3(const vector<int> &v);            // function to calculate top 3 grades for the final and midterm.

/*
 * This function calculates the mean of a the vector of grades, and returns the mean as a double.
 * Author : Hamza Zm.
 */
double mean(vector<int> v)
{
    double sum = 0.0;
    double mean = 0.0;
    for (int i = 0; i < v.size(); ++i)
    {

        sum += v[i];
    }

    mean = sum / v.size();
    return mean;
}

/*
 * This function calculates the standard deviation of a vector of grades.
 * using the formula given in the assignment.
 * Author : Hamza Zm.
 */
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

    double stdDev = sqrt(sumSqauredDiff / v.size() - 1);
    return stdDev;
}

/*
 * This function assigns letter grades based on the score, mean, and standard deviation.
 * It uses the grading on the curve algorithm specified in our assignment instructions.
 * Author : Hamza Zm.
 */
char letter(int score, double m, double s)
{

    if (score < m - 1.5 * s)
    {

        return 'E';
    }
    else if (score < m - 0.5 * s)
    {

        return 'D';
    }
    else if (score < m + 0.5 * s)
    {
        return 'C';
    }
    else if (score < m + 1.5 * s)
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
    // Calculate the mean and standard deviation for midterm and final grades.
    double meanMid = mean(midterm);
    double meanFin = mean(final);
    double stddevMid = stddev(midterm, meanMid);
    double stddevFin = stddev(final, meanFin);

    // Output the data as specified in our assignment instructions.

    cout << "Code      Midterm Grade Final Grade" << endl;
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < codes.size(); ++i)
    {
        cout << left << std::setw(8) << codes[i]
             << right << std::setw(7) << midterm[i]
             << setw(6) << letter(midterm[i], meanMid, stddevMid)
             << setw(7) << final[i]
             << setw(6) << letter(final[i], meanFin, stddevFin)
             << endl;
    }

    cout << endl;
    cout << "Midterm mean: " << fixed << setprecision(1) << setw(30) << meanMid << endl;
    cout << "Midterm std:  " << fixed << setprecision(1) << setw(30) << stddevMid << endl;
    cout << "Final mean:   " << fixed << setprecision(1) << setw(30) << meanFin << endl;
    cout << "Final std:    " << fixed << setprecision(1) << setw(30) << stddevFin << endl;

    cout << endl;

    cout << "Midterm Top 3 Scores:" << setw(16);
    top3(midterm);

    cout << "Final Top 3 Scores:" << setw(18);
    top3(final);
}
