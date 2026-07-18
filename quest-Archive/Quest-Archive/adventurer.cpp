#include "adventurer.h"

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


string Adventurer::getName() const
{
    return name;
}

int Adventurer::getLevel() const
{
    return level;
}

int Adventurer::getQuestsCompleted() const
{
    return questsCompleted;
}

double Adventurer::getGoldEarned() const
{
    return goldEarned;
}

string Adventurer::getRank() const
{
    return rank;
}

// ====================================
// Setters
// ====================================

void Adventurer::setName(string name)
{
    this->name = name;
}

void Adventurer::setLevel(int level)
{
    if (level > 0)
    {
        this->level = level;
    }
}

void Adventurer::setQuestsCompleted(int questsCompleted)
{
    if (questsCompleted >= 0)
    {
        this->questsCompleted = questsCompleted;

        // Recalculate rank whenever quests change
        updateRank();
    }
}

void Adventurer::setGoldEarned(double goldEarned)
{
    if (goldEarned >= 0)
    {
        this->goldEarned = goldEarned;
    }
}

void Adventurer::setRank(string rank)
{
    this->rank = rank;
}