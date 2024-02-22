#include "univariate.h"
#include "polynomial.h"

bool univariate::isUnivariate() const {
    for (int i = 0; i < numTerms; i ++){
        if (terms[i]->getNumVariables() == 1){ // if theres only one variable
            if (terms[i]->getVariables()[0] != variable)// check to see its the correct one
                return false;
        }
        else if (terms[i]->getNumVariables() == 0){//if theres 0 variables its fine
            continue;
        }
        else{// if there not 1/0 it cant be correct
            return false;
        }
        if (terms[i]->getDegree() > degree ){//if the degree is over max
            return false;
        }  
    }
    return true;// all terms are shap
}

void univariate::clearTerms() {
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

univariate::univariate(int d, char c) : polynomial(), degree(d), variable(c) {}

univariate::univariate(term** t, int n) : polynomial(t, n), degree(2), variable('x') {
    if (numTerms > 0){
        degree = terms[0]->getDegree();
        if (terms[0]->getNumVariables() > 0)
        {
            variable = terms[0]->getVariables()[0];
        }            
    }
    if (!isUnivariate()) clearTerms();
}

univariate::univariate(const char* input) : polynomial(input), degree(2), variable('x') {
    //cout<<"u"<<__LINE__<<":"<<*this;
    if (numTerms > 0){
        degree = terms[0]->getDegree();
        if (terms[0]->getNumVariables() > 0)
        {
            variable = terms[0]->getVariables()[0];
        }            
    }
    if (!isUnivariate()) clearTerms();
}

univariate::univariate(const univariate& other) : polynomial(other), degree(other.degree), variable(other.variable) {}

univariate::univariate(const polynomial& other) : polynomial(other), degree(2), variable('x') {
    if (numTerms > 0){
        degree = terms[0]->getDegree();
        if (terms[0]->getNumVariables() > 0)
        {
            variable = terms[0]->getVariables()[0];
        }            
    }
    if (!isUnivariate()) clearTerms();
}

univariate::univariate(term t) : polynomial(t), degree(2), variable('x') {
    if (numTerms > 0){
        degree = terms[0]->getDegree();
        if (terms[0]->getNumVariables() > 0)
        {
            variable = terms[0]->getVariables()[0];
        }            
    }
    if (!isUnivariate()) clearTerms();
}

univariate& univariate::operator=(const univariate& other) {
    if (this != &other) {
        polynomial::operator=(other);
        degree = other.degree;
        variable = other.variable;
    }
    return *this;
}

istream& operator>>(istream& is, univariate& u) {
    std::string par;
    std::getline(is, par);    
    univariate temp(par.c_str());
    if (temp.numTerms != 0)
        u = temp;
    return is;
}

polynomial* univariate::operator!() const {
    term** temp = new term*[numTerms];
    for (int i = 0; i < numTerms; i++)
        temp[i] = new term(!(*terms[i]));
    polynomial* result = new univariate(temp, numTerms);
    for (int i = 0; i < numTerms; i++)
        delete temp[i];
    delete[] temp;
    return result;
}

polynomial* univariate::operator()(char* vars, int* vals, int numVals) const {
    term** temp = new term*[numTerms];
    for (int i = 0; i < numTerms; i++)
        temp[i] = new term((*terms[i])(vars,vals,numVals));
    polynomial* result = new univariate(temp, numTerms);
    for (int i = 0; i < numTerms; i++)
        delete temp[i];
    delete[] temp;
    return result;
}

polynomial* univariate::operator()(string inp) const {
    term** temp = new term*[numTerms];
    for (int i = 0; i < numTerms; i++)
        temp[i] = new term((*terms[i])(inp));
    polynomial* result = new univariate(temp, numTerms);
    for (int i = 0; i < numTerms; i++)
        delete temp[i];
    delete[] temp;
    return result;
}

polynomial* univariate::operator+(const polynomial& other) const {
    univariate* result = new univariate(*this);

    for (int i = 0; i < other.getNumTerms(); i++)
        result->addOrRemoveTerm(other.getTerms()[i]);

    return result;
}

polynomial* univariate::operator-(const polynomial& other) const {
    polynomial* temp = !other;
    polynomial* result = *this + *temp;
    delete temp;
    return result;
}

polynomial* univariate::operator*(const polynomial& other) const {
    univariate* result = new univariate(*this);
    result->clearTerms();

    for (int i = 0; i < other.getNumTerms(); i++)
        for (int j = 0; j < numTerms; j++){
            term temp = *other.getTerms()[i] * *terms[j];
            result->addOrRemoveTerm(&temp);
        }
 
    return result;
}

polynomial& univariate::operator+=(const polynomial& other) {
    univariate* result = new univariate(*this);

    for (int i = 0; i < other.getNumTerms(); i++)
        result->addOrRemoveTerm(other.getTerms()[i]);

    if (result->isUnivariate())
        *this = *result;

    delete result;
    return *this;
}

polynomial& univariate::operator-=(const polynomial& other) {
    polynomial* neg = !other;
    univariate* result = new univariate(*this);

    for (int i = 0; i < neg->getNumTerms(); i++)
        result->addOrRemoveTerm(neg->getTerms()[i]);
    delete neg;
    if (result->isUnivariate())
        *this = *result;

    delete result;
    return *this;    
}

polynomial& univariate::operator*=(const polynomial& other) {
    univariate* result = new univariate(*this);
    result->clearTerms();

    for (int i = 0; i < other.getNumTerms(); i++)
        for (int j = 0; j < numTerms; j++){
            term temp = *other.getTerms()[i] * *terms[j];
            result->addOrRemoveTerm(&temp);
        }
    
    if (result->isUnivariate())
        *this = *result;
    delete result;
    return *this;
}
