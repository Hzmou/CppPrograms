/*
 * This is a basic cpp program that uses control flow concepts to output information about
 * packages.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

  double weight;   // weight of the package.  
  double weightSum = 0.0; // sum of all weights.
  double weightAverage;   // average weight of all packages.
  double minWeight, maxWeight; // min and max weights.
  int cat1 = 0, cat2 = 0, cat3 = 0, cat4 = 0; // number of packages in each category.
  // start the program - prompt the user for input.

  cout << "Enter packages weights (0 to end sequence):  ";
  // intialize the first weight to start the loop.
  int count = 0;

  cin >> weight;
  minWeight = maxWeight = weight; // set min and max to the first weight.


  // loop until the user enters 0.
  // this is the sentinel value to end the loop.
  while (weight != 0)
  {

    count++;

    weightSum += weight; // add the weight to the sum.
    // check if the weight is less than the min or greater than the max.
    // if so, set the min or max to the weight.
    // this is done to find the min and max weights.

    if (weight < minWeight)
      minWeight = weight;
    if (weight > maxWeight)
      maxWeight = weight;
    // check the weight and increment the appropriate category counter.
    // this is done to find the number of packages in each category.
    // the categories are:
    // 1: 0.0 - 2.0
    // 2: 2.1 - 5.0
    // 3: 5.1 - 8.0
    // 4: 8.1 - 10.0
    if (weight <= 2.0)
    {
      cat1++;
    }
    else if (weight <= 5.0)
    {
      cat2++;
    }
    else if (weight <= 8.0)
    {
      cat3++;
    }
    else if (weight <= 10.0)
    {
      cat4++;
    }

    cin >> weight;
  }
  // calculate the average weight.
  // this is done by dividing the sum of all weights by the number of packages.
  weightAverage = weightSum / count;


  // print the results. output the report. 
  cout << fixed << setprecision(2);
  cout << "Number of packages: " << count << endl;
  cout << "Average weight: " << weightAverage << endl;
  cout << "Minimum weight: " << minWeight << endl;
  cout << "Maximum weight: " << maxWeight << endl;

  // print the number of packages in each category.
  cout << "\nCategory   Number\n";
  cout << "1          " << cat1 << endl;
  cout << "2          " << cat2 << endl;
  cout << "3          " << cat3 << endl;
  cout << "4          " << cat4 << endl;
}