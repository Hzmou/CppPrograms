
/* Complete implementation for the adventurer class. */

#include "adventurer.h"
#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

// default constructor. 

Adventurer::Adventurer()
{
    name = "Unknown";
    level = 1;
    questsCompleted = 0;
    goldEarned = 0.0;
    rank = "Novice";
}

// parameterized constructor.

Adventurer::Adventurer(string name, int level){

    this->name = name;
    this->level = level;


}

void Adventurer::updateRank(){
   
    if(){
        
    }



}