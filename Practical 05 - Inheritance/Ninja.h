#ifndef NINJA_H
#define NINJA_H

#include "Soldier.h"

class Mage; // Forward declaration
class Brute; // Forward declaration

class Ninja : private Soldier {
private:
    int moveCount;

public:
    Ninja(std::string name, double health, double strength);

    bool takeDamage(double damage);
    Ninja& operator=(const Ninja& ninja);
    bool isAlive() const;
    bool attack(Brute* brute);
    bool attack(Ninja* ninja);
    bool attack(Mage* mage);
    void arm(Sword* sword);

    //std::string printSoldier() const;
};

#endif // NINJA_H
