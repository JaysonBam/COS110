#include "Mage.h"
#include "Brute.h"
#include "Ninja.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>

Mage::Mage(std::string name, double health, double strength) : Soldier(name, health, strength) {
    shadowBone = NULL;
}

void Mage::armShadow(ShadowBone* shadowBone) {
    if (shadowBone==NULL || shadowBone == this->shadowBone) return;
    if (this->shadowBone != NULL) delete this->shadowBone;
    this->shadowBone = shadowBone;
}

Mage& Mage::operator=(const Mage& mage) {
    if (this == &mage) return *this;

    if (shadowBone != NULL){
        delete shadowBone;
        shadowBone = NULL;
    }

    Soldier::operator=(mage);
    if (mage.shadowBone == NULL)
        shadowBone = NULL;
    else 
        shadowBone = new ShadowBone(*mage.shadowBone);
    
    return *this;
}

std::string Mage::printSoldier() {
    std::ostringstream ss;
    ss << Soldier::printSoldier();
    if (shadowBone!=NULL) ss << shadowBone->printSword();
    return ss.str();
}

bool Mage::attack(Brute* brute) {
    if (brute == NULL || !brute->isAlive()) {
        return false; 
    }

    if (shadowBone != NULL) {
        if (brute->takeDamage(shadowBone->damage(strength))) {
            return true;
        }
    }

    if (sword != NULL) {
        if (brute->takeDamage(sword->damage(strength))) {
            return true;
        }
    }

    return false;
}


bool Mage::attack(Ninja* ninja) {
    if (ninja == NULL || !ninja->isAlive()) {
        return false;
    }

    if (shadowBone != NULL) {
        if (ninja->takeDamage(shadowBone->damage(strength))) {
            return true;
        }
    }

    if (sword != NULL) {
        if (ninja->takeDamage(sword->damage(strength))) {
            return true;
        }
    }

    return false;
}

bool Mage::attack(Mage* mage) {
    if (mage == NULL || !mage->isAlive()) {
        return false;
    }

    if (sword != NULL) {
        if (mage->takeDamage(sword->damage(strength))) {
            return true;
        }
    }

    return false;
}