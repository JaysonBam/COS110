#ifndef LINEAR_H
#define LINEAR_H

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "univariate.h"

using namespace std;

class linear : public univariate {
   public:
    linear(char c);
    linear(term** t, int n);
    linear(const char* input);
    linear(const linear& other);
    linear(const polynomial& other);
    linear(term t);
    void printRoots() const;
};

#endif