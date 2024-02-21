#include "ellipse.h"
#include <cmath>

using namespace std;

bool ellipse::isEllipse() const {
    if (numTerms != 3) return false;
    if (terms[0]->getDegree() != 2) return false;
        if (terms[0]->getNumVariables() != 1) return false;

    if (terms[1]->getDegree() != 2) return false;
        if (terms[1]->getNumVariables() != 1) return false;

    if (terms[2]->getDegree() != 0) return false;
        if (terms[2]->getNumVariables() != 0) return false;

    return true;  
}

ellipse::ellipse(char c1, char c2) : bivariate(2, c1, c2) {
}

ellipse::ellipse(term** t, int n) : bivariate(t, n) {
    degree = 2;
    if (!isEllipse()) clearTerms();
}

ellipse::ellipse(const char* input) : bivariate(input) {
    degree = 2;
    if (!isEllipse()) clearTerms();
}

ellipse::ellipse(const ellipse& other) : bivariate(other) {
    degree = 2;
    if (!isEllipse()) clearTerms();
}

ellipse::ellipse(const polynomial& other) : bivariate(other) {
    degree = 2;
    if (!isEllipse()) clearTerms();
}

ellipse::ellipse(term t) : bivariate(t) {
    degree = 2;
    if (!isEllipse()) clearTerms();
}

void ellipse::printStats() const {
    if (!isEllipse()){
        cout<<"Not a real ellipse\n";
        return;
    }
    float c = (*terms[0])[-1];
    float d = (*terms[1])[-1];
    float f = (*terms[2])[-1];
    if (f>=0){
        cout<<"Not a real ellipse\n";
        return;
    }
    float a = sqrt(-1*f/c);
    float b = sqrt(-1*f/d);
    char c1 = min(v1,v2);
    char c2 = max(v1,v2);
    double pi = 3.14159265358979323846;
    std::cout << std::fixed << std::setprecision(2);
    cout<<"Area = " << pi*a*b <<" units^2."
        <<"Perimeter = " << 2*pi*sqrt((a*a+b*b)/2) << " units."
        <<"Intercepts : "<<c1<<" = "<<a<<" , "<<c1<<" = "<<-1*a<<" , "<<c2<<" = "<<b<<" , "<<c2<<" = "<<-1*b<<endl;

}