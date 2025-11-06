

/* Impelementation of the monster class.*/

#include "Monster.h"

Monster::Monster(int hp)
{

    mhp = hp;
}

int Monster::getHp()
{

    return mhp;
}

void Monster::takeDamage(int amount)
{

    mhp -= amount;

    if (mhp < 0)
    {
        mhp = 0;
    }
}