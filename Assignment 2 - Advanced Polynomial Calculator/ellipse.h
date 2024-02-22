#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "bivariate.h"

using namespace std;

class ellipse : public bivariate {
   private:
    bool isEllipse() const;

   public:
    ellipse(char c1, char c2);
    ellipse(term** t, int n);
    ellipse(const char* input);
    ellipse(const ellipse& other);
    ellipse(const polynomial& other);
    ellipse(term t);
    void printStats() const;
};

#endif