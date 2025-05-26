
/*
   * This is a basic program in C++ that uses dynamic arrays. The user enters a specified number of friend names
with the best friend stored in the first index of the array followed by "regular" friends in no order.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// function prototypes.

void display(string *friends, int size);
int search(string *friends, int size, string target);
string *resize(const string *smaller, int &cap);

string *resize(const string *smaller, int &cap)
{

   int smallCap = cap;

   // double the capacity.
   cap *= 2;

   string *larger = new string[cap]; // make a new string array with double the size.

   // copy elements from the smallet array to the larger one.

   for (int i = 0; i < smallCap; i++)
   {

      larger[i] = smaller[i];
   }

   // release the smaller array from memory.

   delete[] smaller;
   return larger;
}

int main()
{

int numFriends;




string *friends = new string[numFriends];
}