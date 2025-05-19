/*
  * This is a basic cpp program that uses control flow concepts to output information about
  * packages. 
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){


  double weight;
  cout << "Enter packages weights (0 to end sequence):  ";
  int count =0;


while(weight !=0){
 
cin >> weight;

count++;

}
count = count -1;


   
  cout << "Number of packages: "<<count;

}