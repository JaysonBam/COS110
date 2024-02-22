#ifndef UNIVARIATE_H
#define UNIVARIATE_H

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "polynomial.h"

using namespace std;

class univariate : public polynomial {
   protected:
    int degree;
    char variable;
    bool isUnivariate() const;
    void clearTerms();

   public:
    univariate(int d, char c);
    univariate(term** t, int n);
    univariate(const char* input);
    univariate(const univariate& other);
    univariate(const polynomial& other);
    univariate(term t);
    univariate& operator=(const univariate& other);

    friend istream& operator>>(istream& is, univariate& u);
    polynomial* operator!() const;
    polynomial* operator()(char* vars, int* vals, int numVals) const;
    polynomial* operator()(string inp) const;

    virtual polynomial* operator+(const polynomial& other) const;
    virtual polynomial& operator+=(const polynomial& other);
    virtual polynomial* operator-(const polynomial& other) const;
    virtual polynomial& operator-=(const polynomial& other);
    virtual polynomial* operator*(const polynomial& other) const;
    virtual polynomial& operator*=(const polynomial& other);
};

#endif