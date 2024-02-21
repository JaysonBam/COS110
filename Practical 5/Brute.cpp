#include "Brute.h"
#include "Mage.h"
#include "Ninja.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>

Brute::Brute(std::string name, double health, double strength) : Soldier(name, health, strength){
    rageMeter = 0.0;
}

std::string Brute::printSoldier() {
    std::ostringstream ss;
    ss << Soldier::printSoldier();
    ss << "Rage meter: " << rageMeter << "\n";
    return ss.str();
}

Brute& Brute::operator=(const Brute& brute) {
    if (this == &brute) return *this;

    Soldier::operator=(brute);
    rageMeter = brute.rageMeter;

    return *this;
}

bool Brute::attack(Mage* mage) {
    if (mage == NULL || !mage->isAlive() || sword == NULL) {return false;}

    double newStrength = strength;
    if (rageMeter >= 10)
        newStrength = strength*2 + strength*(rageMeter-10)*0.1;

    if (mage->takeDamage(sword->damage(newStrength))) {
        rageMeter = 0.0;
        return true; 
    }
    else{
        rageMeter++;
        return false;
    }
}

bool Brute::attack(Ninja* ninja) {
    if (ninja == NULL || !ninja->isAlive() || sword == NULL) {return false;}

    double newStrength = strength;
    if (rageMeter >= 10)
        newStrength = strength*2 + strength*(rageMeter-10)*0.1;

    if (ninja->takeDamage(sword->damage(newStrength))) {
        rageMeter = 0.0;
        return true; 
    }
    else{
        rageMeter++;
        return false;
    }
}

bool Brute::attack(Brute* brute) {
    if (brute == NULL || !brute->isAlive() || sword == NULL) {return false;}

    double newStrength = strength;;
    if (rageMeter >= 10)
        newStrength = strength*2 + strength*(rageMeter-10)*0.1;
    newStrength /= 2;

    if (brute->takeDamage(sword->damage(newStrength))) {
        rageMeter = 0.0;
        return true; 
    }
    else{
        rageMeter++;
        return false;
    }
}