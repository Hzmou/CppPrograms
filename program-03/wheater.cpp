
/*
 * This is a Basic program in C++ that uses functions and file I/O to read from a file
 * and output the weather data to the console taken from the file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

// function prototypes.
void openfile(ifstream &fin);                          // filenames are read until the file is opened.
double convertToCelsius(double fahrenheit);            // function to convert fahrenheit to celsius.
double windChill(double velocity, double temperature); // function to calculate wind chill.

void openfile(ifstream &fin)
{
  string fileName;
    cout << "Enter input file name : ";
    cin >> fileName;
    fin.open(fileName);

    // Keep prompting until the file opens successfully
    while (!fin.is_open())
    {
        cout << "File could not be opened. Please try again." << endl;
        fin.clear(); // Clear any error flags
        cout << "Enter input file name : ";
        cin >> fileName;
        fin.open(fileName);
    }
}

int main()
{
  string town;
  double windSpeed;
  string direction;
  double tempF;
  double tempC;
  double windChill;

  ifstream inputFile;

  openfile(inputFile);
  getline(inputFile, town);
  inputFile >> windSpeed >> direction >> tempF >> tempC >> windChill;

  cout << left << setw(10) << "Town"
       << setw(12) << "Wind Speed"
       << setw(12) << "Direction"
       << setw(10) << "Temp (F)"
       << setw(10) << "Temp (C)"
       << setw(14) << "Wind Chill (F)" << endl;

  while (!inputFile.fail())
  {

    cout << left << setw(10) << town
         << setw(12) << fixed << setprecision(1) << windSpeed
         << setw(12) << direction
         << setw(10) << fixed << setprecision(1) << tempF
         << setw(10) << fixed << setprecision(1) << tempC;

    if (windSpeed < 3.0 || tempF > 50.0)
    {
      cout << setw(14) << "N/A";
    }
    else
    {
      cout << setw(14) << fixed << setprecision(1) << windChill;
    }
    cout << endl;

    inputFile.ignore(); // To move to the next line for getline
    getline(inputFile, town);
    inputFile >> windSpeed >> direction >> tempF >> tempC >> windChill;
  }
}