#ifndef TERM_H
#define TERM_H

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class term {
   private:
    int coefficient;
    int numVariables;
    char* variables;
    int* powers;
    void addVariable(char var, int pow);
    void removeVariable(char var);

   public:
    term();
    term(const term& other);
    term(int c, int n, char* v, int* p);
    term(const char* input);
    term& operator=(const term& other);
    ~term();

    char* getVariables() const;
    int getNumVariables() const;
    int getDegree() const;
    int getVarIndex(char var) const;

    string operator~() const;
    friend ostream& operator<<(ostream& os, const term& t);
    friend istream& operator>>(istream& is, term& t);
    const term operator*(const term& other) const;
    term& operator*=(const term& other);
    const term operator()(char* vars, int* vals, int numVals) const;
    const term operator()(string inp) const;
    bool operator==(const term& other) const;
    bool operator<(const term& other) const;
    bool operator>(const term& other) const;
    int& operator[](int idx);
    const term operator!() const;
};

#endif