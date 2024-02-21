#ifndef BRUTE_H
#define BRUTE_H

#include "Soldier.h"

class Mage; // Forward declaration
class Ninja; // Forward declaration

class Brute : public Soldier {
private:
    double rageMeter;

public:
    Brute(std::string name, double health, double strength);

    std::string printSoldier();
    Brute& operator=(const Brute& brute);
    bool attack(Mage* mage);
    bool attack(Ninja* ninja);
    bool attack(Brute* brute);
};

#endif // BRUTE_H
