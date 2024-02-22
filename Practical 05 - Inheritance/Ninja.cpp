#include "Ninja.h"
#include "Brute.h"
#include "Mage.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>

Ninja::Ninja(std::string name, double health, double strength) : Soldier(name, health, strength) {
    moveCount = 0;
}

bool Ninja::takeDamage(double damage) {
    if (moveCount == 2){
        moveCount = 0;
        return false;
    }        
    else{
        moveCount++;
        return Soldier::takeDamage(damage);        
    }
}

Ninja& Ninja::operator=(const Ninja& ninja) {
    if (this == &ninja) return *this;

    Soldier::operator=(ninja);
    moveCount = ninja.moveCount;

    return *this;
}

bool Ninja::isAlive() const{
    return Soldier::isAlive();
}

bool Ninja::attack(Brute* brute) {
    if (brute == NULL || !brute->isAlive() || sword == NULL) return false;
    return (brute->takeDamage(sword->damage(strength)));
}

bool Ninja::attack(Ninja* ninja) {
    if (ninja == NULL || !ninja->isAlive() || sword == NULL) return false;
    return (ninja->takeDamage(sword->damage(strength)));
}

bool Ninja::attack(Mage* mage) {
    if (mage == NULL || !mage->isAlive() || sword == NULL) return false;
    return (mage->takeDamage(sword->damage(strength)));
}

void Ninja::arm(Sword* sword){
    Soldier::arm(sword);
}

// std::string Ninja::printSoldier() const{
//     std::ostringstream ss;
//     ss << Soldier::printSoldier();
//     ss << "Move counter: " << moveCount << "\n";
//     return ss.str();
// }