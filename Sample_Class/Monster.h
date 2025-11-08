#pragma once 

class Monster{

public:

Monster(int hp); //constructor for the class. 
int getHp();
void takeDamage(int amount);

private:

int mhp;

};

