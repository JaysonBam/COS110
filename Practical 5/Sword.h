#ifndef SWORD_H
#define SWORD_H

#include <string>
#include <cmath>

class Sword {
private:
    std::string name;

protected:
    int level;
    double xp;
    double attack;
    int getXPForNextLevel();
    void addXP(double damage);

public:
    Sword(std::string name, double attack);
    Sword(const Sword& sword);
    double damage(int playerStrength);
    std::string printSword();
};

#endif
