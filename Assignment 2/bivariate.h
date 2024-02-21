#ifndef BIVARIATE_H
#define BIVARIATE_H

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "polynomial.h"

using namespace std;

class bivariate : public polynomial {
   protected:
    int degree;
    char v1;
    char v2;
    void clearTerms();
   public:
    bool isBivariate() const;

   public:
    bivariate(int d, char c1, char c2);
    bivariate(term** t, int n);
    bivariate(const char* input);
    bivariate(const bivariate& other);
    bivariate(const polynomial& other);
    bivariate(term t);
    bivariate& operator=(const bivariate& other);

    friend istream& operator>>(istream& is, bivariate& u);
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