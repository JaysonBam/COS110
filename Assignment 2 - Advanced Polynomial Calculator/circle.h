#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "bivariate.h"

using namespace std;

class circle : public bivariate {
   private:
    bool isCircle() const;

   public:
    circle(char c1, char c2);
    circle(term** t, int n);
    circle(const char* input);
    circle(const circle& other);
    circle(const polynomial& other);
    circle(term t);
    void printStats() const;
};

#endif