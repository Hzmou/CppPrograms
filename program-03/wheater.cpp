
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


/*
  * This function prompts the user for a file name and attempts to open it.
  * If the file cannot be opened, it will keep prompting the user until a valid file is provided.
  * The function takes a reference to an ifstream object as a parameter.
  * Author: Hamza Zm.
*/
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


/*
  * This function converts a temperature from Fahrenheit to Celsius.
  * The formula used is: C = (F - 32) * 5 / 9
  * The function takes a double value representing the temperature in Fahrenheit
  * and returns the converted temperature in Celsius.
  * Author: Hamza Zm
*/
double convertToCelsius(double fahrenheit)
{
  return (fahrenheit - 32) * 5 / 9;
}


/*
  * This function calculates the wind chill based on the wind speed and temperature.
  * The formula used is: W = 35.74 + 0.6215 * T - 35.75 * V^0.16 + 0.4275 * T * V^0.16
  * where W is the wind chill, T is the temperature in Fahrenheit, and V is the wind speed in mph.
  * The function takes two double values: velocity (wind speed) and temperature (in Fahrenheit)
  * and returns the calculated wind chill in Fahrenheit.
 
  * Note: The wind chill is only calculated if the wind speed is greater than 3.0 mph
  * and the temperature is less than or equal to 50.0 degrees Fahrenheit.
  * If these conditions are not met, the function returns 0.0. 
  * Author: Hamza Zm
*/
double windChill(double velocity, double temperature)
{
  if (velocity > 3.0 || temperature <= 50.0)
  {

    return (35.74 + 0.6215 * temperature - 35.75 * pow(velocity, 0.16) + 0.4275 * temperature * pow(velocity, 0.16));
  }
  else
  {
    return 0.0;
  }
}

/*
   * Main function to read weather data from a file and display it in a formatted table.
   * It uses functions to open the file, convert temperatures, and calculate wind chill.
   * The program reads the town name, wind speed, direction, and temperature from the file,
   * and outputs the data in a formatted table.
   * It also calculates the average temperature in Fahrenheit and displays it at the end.   
   * Author: Hamza Zm.
*/
int main()
{
  string town;
  double windSpeed;
  string direction;
  double tempF;
  double tempC;
  double windChillF;
  int count = 0;
  double tempSum = 0.0;

  ifstream inputFile; // Declare the input file stream

  openfile(inputFile); // Call the function to open the file


  // print the labels for the table. 
  cout << left << setw(10) << "Town"
       << setw(12) << "Wind Speed"
       << setw(12) << "Direction"
       << setw(10) << "Temp (F)"
       << setw(10) << "Temp (C)"
       << setw(14) << "Wind Chill (F)" << endl;


  // Read data from the file until the end of the file is reached.
  while (getline(inputFile, town) &&
         (inputFile >> windSpeed) &&
         (inputFile >> direction) &&
         (inputFile >> tempF))
  {

    inputFile.ignore(); // Ignore the newline character after reading tempF.

    tempC = convertToCelsius(tempF); // Convert temperature to Celsius
    windChillF = windChill(windSpeed, tempF); // Calculate wind chill.
    
    // Output the data in a formatted table.
    // Use fixed and setprecision to control the number of decimal places.
    cout << left << setw(10) << town
         << setw(12) << fixed << setprecision(1) << windSpeed
         << setw(12) << direction
         << setw(10) << fixed << setprecision(1) << tempF
         << setw(10) << fixed << setprecision(1) << tempC;
    // Check if wind speed is less than 3.0 or temperature is greater than or equal to 50.0
    // If so, print "N/A" for wind chill; otherwise, print the calculated wind chill.
    if (windSpeed < 3.0 || tempF >= 50.0)
    {
      cout << setw(14) << "N/A";
    }
    else
    {
      cout << setw(14) << fixed << setprecision(1) << windChillF;
    }
    cout << endl;

    count++;  // keep a count of the number of data sets processed.
    tempSum += tempF;  // accumulate the sum of temperatures in Fahrenheit to calculate the average.
  }

  cout << endl;
  cout << "Total Data sets: " << count << endl; // Print the total number of data sets processed.
  double averageTempF = tempSum / count;
  // Print the average temperature in Fahrenheit.
  cout << setprecision(2) << "Average temperature in Fahrenheit: " << averageTempF << endl; 
}