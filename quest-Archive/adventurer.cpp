
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

Adventurer::Adventurer(string name, int level)
{

    this->name = name;
    this->level = level;
    this->questsCompleted = 0;
    this->goldEarned = 0.0;
    this->rank = "Novice";
}

// constructor that makes it easier to load data into out.txt file.
Adventurer::Adventurer(
    string name,
    int level,
    int questsCompleted,
    double goldEarned,
    string rank)
{
    this->name = name;
    this->level = level;
    this->questsCompleted = questsCompleted;
    this->goldEarned = goldEarned;
    this->rank = rank;
}

void Adventurer::updateRank()
{

    if (questsCompleted >= 50)
    {

        rank = "Master Adventurer";
    }
    else if (questsCompleted >= 20)
    {

        rank = "Expert Adventurer";
    }
    else if (questsCompleted >= 10)
    {

        rank = "Intermediate Adventurer";
    }
    else
    {

        rank = "Novice Adventurer";
    }
}

// core functions of this class.

/* Record the quest done by the player */
void Adventurer::recordQuest(double goldEarned)
{
    questsCompleted++;
    this->goldEarned += goldEarned;

    // Increase level every 3 quests
    if (questsCompleted % 3 == 0)
    {
        level++;
    }

    updateRank();
}