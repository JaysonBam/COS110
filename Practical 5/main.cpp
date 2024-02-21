#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>

#include "Sword.h"
#include "Mage.h"
#include "Brute.h"
#include "Ninja.h"
#include "Soldier.h"
#include "ShadowBone.h"

int random_int(int low, int high, int avoid = -1) {
    int random_number = rand() % (high - low + 1) + low;
    while (random_number == avoid) {
        random_number = rand() % (high - low + 1) + low;
    }
    return random_number;
}

void testSword(){
    Sword s1("Slay",10);
    Sword s2(s1);
    s1.damage(10);
    s2.printSword();
}

void testShadowBone(){
    ShadowBone sb1("Boo",20,2);
    ShadowBone sb2(sb1);
    sb1.damage(10);
    sb2.printSword();
}

void testSoldier(){
    Soldier soldier1("Pete",100,100);
    Soldier soldier2("Pet",10,10);
    Sword* sword1 = new Sword("Sword1", 15.0);
    soldier1.printSoldier();
    soldier1.arm(sword1);
    soldier1.takeDamage(10);
    soldier1.takeDamage(100000);
    soldier1.isAlive();
    soldier2=soldier1=soldier1;
}

void testMage(){
    Mage mage1("Pete",100,100);
    Mage mage2("Pet",10,10);
    ShadowBone* shadowBone1 = new ShadowBone("ShadowBone1", 20.0, 1.5);
    mage1.armShadow(shadowBone1);
    mage1.printSoldier();
    mage1=mage1;
    delete shadowBone1;
}

void testBrute(){
    Brute soldier1("Pete",100,100);
    Brute soldier2("Pet",10,10);
    soldier1.printSoldier();
    soldier2=soldier1=soldier1;   
}

void testNinja(){
    Ninja soldier1("Pete",100,100);
    Ninja soldier2("Pet",10,10);
    Sword* sword1 = new Sword("Sword1", 15.0);
    soldier1.arm(sword1);
    soldier1.takeDamage(10);
    soldier1.takeDamage(100000);
    soldier1.isAlive();
    soldier2=soldier1=soldier1;
}

int main() {
    testSword();
    testShadowBone();
    testSoldier();
    testMage();
    testBrute();
    testNinja();
    // Create some swords
    Soldier::aliveSoldiers=0;
    Soldier::deadSoldiers=0;

    Sword* sword1 = new Sword("Sword1", 15.0);
    Sword* sword2 = new Sword("Sword2", 18.0);
    Sword* sword3 = new Sword("Sword3", 12.0);
    Sword* sword4 = new Sword("Sword4", 14.0);
    Sword* sword5 = new Sword("Sword5", 10.0);
    Sword* sword6 = new Sword("Sword6", 11.0);
    ShadowBone* shadowBone1 = new ShadowBone("ShadowBone1", 20.0, 1.5);

    Brute brute1("Brute1", 200.0, 10.0);
    Brute brute2("Brute2", 180.0, 9.0);
    Mage mage1("Mage1", 150.0, 8.0);
    Mage mage2("Mage2", 160.0, 8.5);
    Ninja ninja1("Ninja1", 120.0, 7.0);
    Ninja ninja2("Ninja2", 130.0, 7.5);

    Mage* mages[2];
    Brute* brutes[2];
    Ninja* ninjas[2];

    // Assign instances to the array
    mages[0] = &mage1;
    mages[1] = &mage2;
    brutes[0] = &brute1;
    brutes[1] = &brute2;
    ninjas[0] = &ninja1;
    ninjas[1] = &ninja2;

    brute1.arm(sword1);
    brute2.arm(sword2);
    mage1.arm(sword3);
    mage2.arm(sword4);
    ninja1.arm(sword5);
    ninja2.arm(sword6);
    mage1.armShadow(shadowBone1);

    std::cout << "Before===================================================\n";
    std::cout << mages[0]->printSoldier() << std::endl;
    std::cout << mages[1]->printSoldier() << std::endl;
    std::cout << brutes[0]->printSoldier() << std::endl;
    std::cout << brutes[1]->printSoldier() << std::endl;
    //std::cout << ninjas[0]->printSoldier() << std::endl;
    //std::cout << ninjas[1]->printSoldier() << std::endl;
    std::cout << "Before===================================================\n";

    int round = 0;
    while (Soldier::aliveSoldiers != 1) {
        int m = random_int(0, 5);
        int a = random_int(0, 5, m);

        // Check if the attacking soldier and the target soldier are both alive
        if (m == 0 || m == 1) { // Main is a mage
            if (a == 0 || a == 1) { // Attacking a mage
                if (mages[m]->isAlive() && mages[a]->isAlive()) {
                    round++;
                    std::cout << "Round " << round << "==================\n";
                    mages[m]->attack(mages[a]);
                    std::cout << mages[m]->printSoldier() << std::endl << mages[a]->printSoldier() << std::endl;
                }
            }
            if (a == 2 || a == 3) { // Attacking a brute
                if (mages[m]->isAlive() && brutes[a - 2]->isAlive()) {
                    round++;
                    std::cout << "Round " << round << "==================\n";
                    mages[m]->attack(brutes[a - 2]);
                    std::cout << mages[m]->printSoldier() << std::endl << brutes[a - 2]->printSoldier() << std::endl;
                }
            }
            if (a == 4 || a == 5) { // Attacking a ninja
                if (mages[m]->isAlive() && ninjas[a - 4]->isAlive()) {
                    round++;
                    std::cout << "Round " << round << "==================\n";
                    mages[m]->attack(ninjas[a - 4]);
                    //std::cout << mages[m]->printSoldier() << std::endl << ninjas[a - 4]->printSoldier() << std::endl;
                }
            }
        }
        if (m == 2 || m == 3) { // Main is a brute
            if (a == 0 || a == 1) { // Attacking a mage
                if (brutes[m - 2]->isAlive() && mages[a]->isAlive()) {
                    round++;
                    std::cout << "Round " << round << "==================\n";
                    brutes[m - 2]->attack(mages[a]);
                    std::cout << brutes[m - 2]->printSoldier() << std::endl << mages[a]->printSoldier() << std::endl;
                }
            }
            if (a == 2 || a == 3) { // Attacking a brute
                if (brutes[m - 2]->isAlive() && brutes[a - 2]->isAlive()) {
                    round++;
                    std::cout << "Round " << round << "==================\n";
                    brutes[m - 2]->attack(brutes[a - 2]);
                    std::cout << brutes[m - 2]->printSoldier() << std::endl << brutes[a - 2]->printSoldier() << std::endl;
                }
            }
            if (a == 4 || a == 5) { // Attacking a ninja
                if (brutes[m - 2]->isAlive() && ninjas[a - 4]->isAlive()) {
                    round++;
                    std::cout << "Round " << round << "==================\n";
                    brutes[m - 2]->attack(ninjas[a - 4]);
                    //std::cout << brutes[m - 2]->printSoldier() << std::endl << ninjas[a - 4]->printSoldier() << std::endl;
                }
            }
        }
        if (m == 4 || m == 5) { // Main is a ninja
            if (a == 0 || a == 1) { // Attacking a mage
                if (ninjas[m - 4]->isAlive() && mages[a]->isAlive()) {
                    round++;
                    std::cout << "Round " << round << "==================\n";
                    ninjas[m - 4]->attack(mages[a]);
                    //std::cout << ninjas[m - 4]->printSoldier() << std::endl << mages[a]->printSoldier() << std::endl;
                }
            }
            if (a == 2 || a == 3) { // Attacking a brute
                if (ninjas[m - 4]->isAlive() && brutes[a - 2]->isAlive()) {
                    round++;
                    std::cout << "Round " << round << "==================\n";
                    ninjas[m - 4]->attack(brutes[a - 2]);
                    //std::cout << ninjas[m - 4]->printSoldier() << std::endl << brutes[a - 2]->printSoldier() << std::endl;
                }
            }
            if (a == 4 || a == 5) { // Attacking a ninja
                if (ninjas[m - 4]->isAlive() && ninjas[a - 4]->isAlive()) {
                    round++;
                    std::cout << "Round " << round << "==================\n";
                    ninjas[m - 4]->attack(ninjas[a - 4]);
                    //std::cout << ninjas[m - 4]->printSoldier() << std::endl << ninjas[a - 4]->printSoldier() << std::endl;
                }
            }
        }
    }

    std::cout << "End===================================================\n";
    std::cout << mages[0]->printSoldier() << std::endl;
    std::cout << mages[1]->printSoldier() << std::endl;
    std::cout << brutes[0]->printSoldier() << std::endl;
    std::cout << brutes[1]->printSoldier() << std::endl;
    //std::cout << ninjas[0]->printSoldier() << std::endl;
    //std::cout << ninjas[1]->printSoldier() << std::endl;
    std::cout << "End===================================================\n";

    delete shadowBone1;

    std::cout << "klaar============\n";
    return 0;
}