#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "linear.h"

using namespace std;

linear::linear(char c) : univariate(c,1) {
}

linear::linear(term** t, int n) : univariate(t,n) {
    degree = 1;
    if (!isUnivariate()) clearTerms();
}

linear::linear(const char* input) : univariate(input) {
    degree = 1;
    if (!isUnivariate()) clearTerms();
}

linear::linear(const linear& other) : univariate(other) {
    degree = 1;
    if (!isUnivariate()) clearTerms();
}

linear::linear(const polynomial& other) : univariate(other) {
    degree = 1;
    if (!isUnivariate()) clearTerms();
}

linear::linear(term t) : univariate(t) {
    degree = 1;
    if (!isUnivariate()) clearTerms();
}


void linear::printRoots() const {
    //std::cout<<*this;
    float m = 0;
    float c = 0;

    for (int i = 0; i < numTerms; i++){
        if (terms[i]->getDegree() == 0) c = (*terms[i])[-1];
        if (terms[i]->getDegree() == 1) m = (*terms[i])[-1];
    }
    
    if (m == 0)
        std::cout<<"No roots\n";    
    else
        std::cout<<"Roots : "<<variable<<" = "<<std::fixed << std::setprecision(2)<<(-1*c/m)<<std::endl; 

}