/* header file for the adventurer class. */

#ifndef ADVENTURER_H
#define ADVENTURER_H

#include <string>

class Adventurer
{

private:
    std::string name;
    int level;
    int questsCompleted;
    double goldEarned;
    std::string rank;

    void updateRank();

public:
    // constructor functions.

    Adventurer();
    Adventurer(std::string name, int level);
    // cosntructor that makes it easier to load data into out.txt file.

    // For loading from quests.txt
    Adventurer(
        std::string name,
        int level,
        int questsCompleted,
        double goldEarned,
        std::string rank);

    // core functions.

    void recordQuest(double goldEarned);
    void display() const;

    // getters and setters.

    std::string getName() const;
    int getLevel() const;
    int getQuestsCompleted() const;
    double getGoldEarned() const;
    std::string getRank() const;

    void setName(std::string name);
    void setLevel(int level);
    void setQuestsCompleted(int questsCompleted);
    void setGoldEarned(double goldEarned);
    void setRank(std::string rank);
};

#endif