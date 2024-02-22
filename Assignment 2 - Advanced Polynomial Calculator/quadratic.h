#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "univariate.h"

using namespace std;

class quadratic : public univariate {
   public:
    quadratic(char c);
    quadratic(term** t, int n);
    quadratic(const char* input);
    quadratic(const quadratic& other);
    quadratic(const polynomial& other);
    quadratic(term t);
    void printRoots() const;
};

#endif