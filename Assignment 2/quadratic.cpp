#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "quadratic.h"

using namespace std;

quadratic::quadratic(char c) : univariate(c,2) {
}

quadratic::quadratic(term** t, int n) : univariate(t,n) {
    degree = 2;
    if (!isUnivariate()) clearTerms();
}

quadratic::quadratic(const char* input) : univariate(input) {
    degree = 2;
    if (!isUnivariate()) clearTerms();
}

quadratic::quadratic(const quadratic& other) : univariate(other) {
    degree = 2;
    if (!isUnivariate()) clearTerms();
}

quadratic::quadratic(const polynomial& other) : univariate(other) {
    degree = 2;
    if (!isUnivariate()) clearTerms();
}

quadratic::quadratic(term t) : univariate(t) {
    degree = 1;
    if (!isUnivariate()) clearTerms();
}

void quadratic::printRoots() const {
    float a = 0;
    float b = 0;
    float c = 0;

    for (int i = 0; i < numTerms; i++){
        if (terms[i]->getDegree() == 0) c = (*terms[i])[-1];
        if (terms[i]->getDegree() == 1) b = (*terms[i])[-1];
        if (terms[i]->getDegree() == 2) a = (*terms[i])[-1];
    }

    if (a == 0){
        if (b == 0)
            std::cout<<"No roots\n";    
        else
            std::cout<<"Roots : "<<variable<<" = "<<std::fixed << std::setprecision(2)<<(-1*c/b)<<std::endl;      
    }
    else{
        float d = pow(b,2) - 4*a*c;
        if (d < 0)
            std::cout<<"No roots\n";
        else{
            float r1 = (-b + sqrt(d))/(2*a);
            float r2 = (-b - sqrt(d))/(2*a);
            cout<<"Roots : "<<variable<<" = "<<std::fixed << std::setprecision(2)<<r1<<" , "<<variable<<" = "<<std::fixed << std::setprecision(2)<<r2<<endl;
        }        
    }

}