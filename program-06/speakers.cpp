
/*
  * This is cpp program that uses structures to store data about speakers at a conference. 
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;


/* struct to represent a speakers information.
  * It contains the speaker's name, phone number, topic, and fee.
  * The struct is defined with public access by default.
  */

struct Speaker{

  string name;
  string phone;
  string topic;
  double fee;

};



//function prototypes.
void display (vector<Speaker> speakers);
int search (vector<Speaker> pool, string target);


