#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "term.h"

using namespace std;

class polynomial {
   protected:
    int numTerms;
    term** terms;
    void addOrRemoveTerm(term* t);
    int termIndex(term* t) const;

   public:
    polynomial();
    polynomial(term** t, int n);
    polynomial(const char* input);
    polynomial(const polynomial& other);
    polynomial(term t);
    polynomial& operator=(const polynomial& other);
    ~polynomial();

    term** getTerms() const;
    int getNumTerms() const;

    friend ostream& operator<<(ostream& os, const polynomial& p);
    term* operator[](int idx) const;
    term* operator[](int idx);

    virtual polynomial* operator+(const polynomial& other) const = 0;
    virtual polynomial& operator+=(const polynomial& other) = 0;
    virtual polynomial* operator-(const polynomial& other) const = 0;
    virtual polynomial& operator-=(const polynomial& other) = 0;
    virtual polynomial* operator*(const polynomial& other) const = 0;
    virtual polynomial& operator*=(const polynomial& other) = 0;

    virtual polynomial* operator!() const = 0;
    virtual polynomial* operator()(char* vars, int* vals, int numVals) const = 0;
    virtual polynomial* operator()(string inp) const = 0;
};
#endif