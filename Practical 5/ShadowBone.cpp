#include "ShadowBone.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>

ShadowBone::ShadowBone(std::string name, double attack, double magicMultiplier) : Sword(name, attack) {
    this->magicMultiplier = magicMultiplier;
}

ShadowBone::ShadowBone(const ShadowBone& shadowBone) : Sword(shadowBone) {
    magicMultiplier = shadowBone.magicMultiplier;
}

double ShadowBone::damage(int playerStrength) {
    double result = attack + (attack * ((playerStrength * 0.1 + level * 0.2) + magicMultiplier));
    addXP(result);
    return result;
}

std::string ShadowBone::printSword() {
    std::ostringstream ss;
    ss << Sword::printSword();
    ss << "Magic Multiplier: " << magicMultiplier << "\n";
    return ss.str();
}
