#ifndef SHADOWBONE_H
#define SHADOWBONE_H

#include "Sword.h"

class ShadowBone : public Sword {
private:
    double magicMultiplier;

public:
    ShadowBone(std::string name, double attack, double magicMultiplier);
    ShadowBone(const ShadowBone& shadowBone);
    double damage(int playerStrength);
    std::string printSword();
};

#endif