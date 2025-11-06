

/* main application class that uses the monster header files and it declarations. */

#include "Monster.h"
#include <iostream>


using namespace std;

int main(){

   Monster monster{100};
   monster.takeDamage(50);


   cout << " Monster hp: " << monster.getHp() << "\n";

   return 0;
}


