#include "Soldier.h"
#include <string>
#include <cmath>
#include <sstream>

int Soldier::aliveSoldiers = 0;
int Soldier::deadSoldiers = 0;

Soldier::Soldier(std::string name, double health, double strength) {
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->sword = NULL;
    aliveSoldiers++;
}

Soldier::~Soldier() {
    if (sword!=NULL){
        delete sword;
        sword = NULL;
    }
}

std::string Soldier::printSoldier() {
    std::ostringstream ss;
    ss << "Name: " << name << "\n";
    ss << "Health: " << health << "\n";
    ss << "Strength: " << strength << "\n";
    if (sword!=NULL) ss << sword->printSword();
    return ss.str();
}

void Soldier::arm(Sword* sword) {
    if (sword==NULL || sword == this->sword) return;
    if (this->sword != NULL) delete this->sword;
    this->sword = sword;
}

bool Soldier::takeDamage(double damage) {
    if (damage < 0 || health == 0) return false;
    if (damage >= health){//they dead now
        health = 0;
        deadSoldiers++;
        aliveSoldiers--;
        return true;
    }
    else{//Not dead yet
        health -= damage;
        return false;
    }
}

bool Soldier::isAlive() const {
    return health > 0;
}

Soldier& Soldier::operator=(const Soldier& soldier) {
    if (this == &soldier) return *this;

    if (sword != NULL){
        delete sword;
        sword = NULL;
    }

    name = soldier.name;
    health = soldier.health;
    strength = soldier.strength;
    if (soldier.sword == NULL)
        sword = NULL;
    else 
        sword = new Sword(*soldier.sword);
    
    return *this;
}