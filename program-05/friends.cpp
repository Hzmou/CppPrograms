
/*
 * This is a basic program in C++ that uses dynamic arrays. The user enters a specified number of friend names
 * with the best friend stored in the first index of the array followed by "regular" friends in no order.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// function prototypes.
void display(string *friends, int size);              // function to display the friends list.
int search(string *friends, int size, string target); // search if the friend exits in the friends list.
string *resize(const string *smaller, int &cap);      // double the array capacity if we have reached the cap size.

int main()
{

   int numFriends; // number of friends. This will be the capacity of our array.
   string bestFriend;
   cout << "How Many friends: ";
   cin >> numFriends;

   int cap = numFriends;
   int size = numFriends;
   string *friends = new string[numFriends];

   cout << "enter the name of your Best Friend: ";
   cin >> bestFriend;

   friends[0] = bestFriend;

   // prompt for the rest of the friends.

   for (int i = 1; i < numFriends; ++i)
   {
      cout << "Enter friend name: ";
      cin >> friends[i];
   }

   display(friends, size);

   string newBest;
  

   while (newBest != "quit")
   {

      cout << "\nEnter new best friend name (quit to end): ";
      cin >> newBest;

      // check if it already a best friend.

      if (friends[0] == newBest)
      {
         cout << newBest << " is already your best friend." << endl;
      }
      else
      {

         int index = search(friends, size, newBest);

         if (index != -1)
         {
            // move to  the best friend position, from of the array.
            for (int i = index; i > 0; --i)
            {
               friends[i] = friends[i - 1];
            }
            friends[0] = newBest;
         }
         else
         {

            if (size == cap)
            {
               friends = resize(friends, cap);
            }

            for (int i = size; i > 0; --i)
            {
               friends[i] = friends[i - 1];
            }
            friends[0] = newBest;
            ++size;
         }
      }

       cout << "\nEnter new best friend name (quit to end): ";
       cin >> newBest;
      display(friends, size);
   }
   delete[] friends;
   return 0;
}

/*
 * This function doubles the size of the array if we have reached the cap size.
 * Author: Hamza Zm.
 */
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

/*
 * This function is used to search for a friend in the friends array.
 * Author: Hamza Zm.
 */

int search(string *friends, int size, string target)
{

   // basic linear search to find a friend in the dynamic array.

   for (int j = 0; j < size; ++j)
   {

      if (friends[j] == target)
      {
         return j;
      }
   }

   return -1;
}

/*
 *  Function to display the list of friends and the Best friend tag.
 *  Author: Hamza Zm.
 */
void display(string *friends, int size)
{
   cout << friends[0] << "   " << "** Best Friend **" << endl;

   for (int i = 1; i < size; ++i)
   {

      cout << friends[i] << " ";
      cout << endl;
   }
}