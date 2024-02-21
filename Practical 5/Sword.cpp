#include "Sword.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>

Sword::Sword(std::string name, double attack) {
    this->name = name;
    this->attack = attack;
    xp = 0;
    level = 1;
}

Sword::Sword(const Sword& sword) {
    name = sword.name;
    attack = sword.attack;
    xp = sword.xp;
    level = sword.level;
}

int Sword::getXPForNextLevel() {
    return pow(log(2*(level+1)),3);
}

void Sword::addXP(double damage) {
    xp += damage*0.1;
    if (xp >= getXPForNextLevel()){
        level++;
        xp = 0;
    }
}

double Sword::damage(int playerStrength) {
    double result = attack + (attack * (playerStrength * 0.1 + level * 0.2));
    addXP(result);
    return result;
}


std::string Sword::printSword() {
    std::ostringstream ss;
    ss << "Sword: " << name << "\n";
    ss << "Attack: " << attack << "\n";
    ss << "Level: " << level << "\n";
    ss << "XP: " << xp << "\n";
    return ss.str();
}