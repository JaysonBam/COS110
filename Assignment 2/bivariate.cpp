#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>

#include "bivariate.h"
void bivariate::clearTerms() {
    if (terms != NULL){
        for (int i = 0; i < numTerms; i++)
            if (terms[i] != NULL){
                delete terms[i];
                terms[i]=NULL;
            }                
        delete[] terms;
        terms = NULL;
    }   
    terms = new term*[0];
    numTerms = 0;   
}

bool bivariate::isBivariate() const {
    if (v1 == v2) return false;
    for (int i = 0; i < numTerms; i++){
        if (terms[i]->getDegree()>degree)
            return false;

        if (terms[i]->getNumVariables()==1){// if theres only 1 variable
            if (!(terms[i]->getVariables()[0]==v1 || terms[i]->getVariables()[0]==v2))
                return false;
        }
        else if (terms[i]->getNumVariables()==2){// if theres 2 variables
            if (!(terms[i]->getVariables()[0]==v1 || terms[i]->getVariables()[0]==v2))
                return false;
            if (!(terms[i]->getVariables()[1]==v1 || terms[i]->getVariables()[1]==v2))
                return false;
        }
        else if (terms[i]->getNumVariables()==0){//if theres 0 variables
            //continue;
        }
        else{// if theres more than two variables
            return false;
        }
    }
    return true;// all terms are shap
}


bivariate::bivariate(int d, char c1, char c2) : polynomial(), degree(d), v1(c1), v2(c2) {}

bivariate::bivariate(term** t, int n): polynomial(t,n), degree(2), v1('x'), v2('y') {
    if (numTerms>0){
        degree = terms[0]->getDegree();
        if (terms[0]->getNumVariables() > 0)
        {
            v1 = terms[0]->getVariables()[0];
        }
        for (int i = 0; i < numTerms; i++)
            for (int j = 0; j < terms[i]->getNumVariables(); j++)
                if (v1 != terms[i]->getVariables()[j]) 
                    v2 = terms[i]->getVariables()[j];
    }
    if (!isBivariate()) clearTerms();
}

bivariate::bivariate(const char* input) : polynomial(input), degree(2), v1('x'), v2('y')   {
    if (numTerms>0){
        degree = terms[0]->getDegree();
        if (terms[0]->getNumVariables() > 0)
        {
            v1 = terms[0]->getVariables()[0];
        }
        for (int i = 0; i < numTerms; i++)
            for (int j = 0; j < terms[i]->getNumVariables(); j++)
                if (v1 != terms[i]->getVariables()[j]) 
                    v2 = terms[i]->getVariables()[j];
    }
    if (!isBivariate()) clearTerms();
}

bivariate::bivariate(const bivariate& other) : polynomial(other), degree(other.degree), v1(other.v1), v2(other.v2)  {}

bivariate::bivariate(const polynomial& other) : polynomial(other), degree(2), v1('x'), v2('y') {
    if (numTerms>0){
        degree = terms[0]->getDegree();
        if (terms[0]->getNumVariables() > 0)
        {
            v1 = terms[0]->getVariables()[0];
        }
        for (int i = 0; i < numTerms; i++)
            for (int j = 0; j < terms[i]->getNumVariables(); j++)
                if (v1 != terms[i]->getVariables()[j]) 
                    v2 = terms[i]->getVariables()[j];
    }
    if (!isBivariate()) clearTerms();
}

bivariate::bivariate(term t) : polynomial(t), degree(2), v1('x'), v2('y')  {
    if (numTerms>0){
        degree = terms[0]->getDegree();
        if (terms[0]->getNumVariables() > 0)
        {
            v1 = terms[0]->getVariables()[0];
        }
        for (int i = 0; i < numTerms; i++)
            for (int j = 0; j < terms[i]->getNumVariables(); j++)
                if (v1 != terms[i]->getVariables()[j]) 
                    v2 = terms[i]->getVariables()[j];
    }
    if (!isBivariate()) clearTerms();
}

bivariate& bivariate::operator=(const bivariate& other) {
    if (this != &other){
        polynomial::operator=(other);
        degree = other.degree;
        v1 = other.v1;
        v2 = other.v2;
    }
    return *this;
}

istream& operator>>(istream& is, bivariate& u) {
    std::string par;
    std::getline(is, par);
    bivariate temp(par.c_str());
    if (temp.numTerms != 0)
        u = temp;
    return is;
}

polynomial* bivariate::operator!() const {
    term** temp = new term*[numTerms];
    for (int i = 0; i < numTerms; i++)
        temp[i] = new term(!(*terms[i]));
    polynomial* result = new bivariate(temp, numTerms);
    for (int i = 0; i < numTerms; i++)
        delete temp[i];
    delete[] temp;
    return result;
}

polynomial* bivariate::operator()(char* vars, int* vals, int numVals) const {
    term** temp = new term*[numTerms];
    for (int i = 0; i < numTerms; i++){
        temp[i] = new term((*terms[i])(vars,vals,numVals));
        cout << *temp[i];
    }
        
    polynomial* result = new bivariate(temp, numTerms);
    for (int i = 0; i < numTerms; i++)
        delete temp[i];
    delete[] temp;
    return result;
}

polynomial* bivariate::operator()(string inp) const {
    term** temp = new term*[numTerms];
    for (int i = 0; i < numTerms; i++){
        temp[i] = new term((*terms[i])(inp));
        cout <<i<<':'<< *temp[i];
    }
    polynomial* result = new bivariate(temp, numTerms);
    for (int i = 0; i < numTerms; i++)
        delete temp[i];
    delete[] temp;
    return result;
}

polynomial* bivariate::operator+(const polynomial& other) const {
    bivariate* result = new bivariate(*this);

    for (int i = 0; i < other.getNumTerms(); i++)
        result->addOrRemoveTerm(other.getTerms()[i]);

    return result;
}

polynomial& bivariate::operator+=(const polynomial& other) {
    bivariate* result = new bivariate(*this);

    for (int i = 0; i < other.getNumTerms(); i++)
        result->addOrRemoveTerm(other.getTerms()[i]);

    if (result->isBivariate())
        *this = *result;

    delete result;
    return *this;   
}

polynomial* bivariate::operator-(const polynomial& other) const {
    polynomial* temp = !other;
    polynomial* result = *this + *temp;
    delete temp;
    return result;
}

polynomial& bivariate::operator-=(const polynomial& other) {
    polynomial* neg = !other;
    bivariate* result = new bivariate(*this);

    for (int i = 0; i < neg->getNumTerms(); i++)
        result->addOrRemoveTerm(neg->getTerms()[i]);
    delete neg;
    if (result->isBivariate())
        *this = *result;

    delete result;
    return *this; 
}

polynomial* bivariate::operator*(const polynomial& other) const {
    bivariate* result = new bivariate(*this);
    result->clearTerms();

    for (int i = 0; i < other.getNumTerms(); i++)
        for (int j = 0; j < numTerms; j++){
            term temp = *other.getTerms()[i] * *terms[j];
            result->addOrRemoveTerm(&temp);
        }
 
    return result;
}

polynomial& bivariate::operator*=(const polynomial& other) {
    bivariate* result = new bivariate(*this);
    result->clearTerms();

    for (int i = 0; i < other.getNumTerms(); i++)
        for (int j = 0; j < numTerms; j++){
            term temp = *other.getTerms()[i] * *terms[j];
            result->addOrRemoveTerm(&temp);
        }
    
    if (result->isBivariate())
        *this = *result;
    delete result;
    return *this;
}