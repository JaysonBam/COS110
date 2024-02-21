#include "circle.h"
#include <cmath>

using namespace std;

bool circle::isCircle() const {
    if (numTerms != 3) return false;
    if (terms[0]->getDegree() != 2) return false;
        if (terms[0]->getNumVariables() != 1) return false;

    if (terms[1]->getDegree() != 2) return false;
        if (terms[1]->getNumVariables() != 1) return false;

    if (terms[2]->getDegree() != 0) return false;
        if (terms[2]->getNumVariables() != 0) return false;

    if ((*terms[0])[-1] != (*terms[1])[-1]) return false;
    return true;
}

circle::circle(char c1, char c2) : bivariate(2, c1, c2) {
}

circle::circle(term** t, int n) : bivariate(t, n) {
    degree = 2;
    if (!isCircle()) clearTerms();
}

circle::circle(const char* input) : bivariate(input) {
    degree = 2;
    if (!isCircle()) clearTerms();
}

circle::circle(const circle& other) : bivariate(other) {
    degree = 2;
    if (!isCircle()) clearTerms();
}

circle::circle(const polynomial& other) : bivariate(other) {
    degree = 2;
    if (!isCircle()) clearTerms();
}

circle::circle(term t) : bivariate(t) {
    degree = 2;
    if (!isCircle()) clearTerms();
}

void circle::printStats() const {
    if (!isCircle()){
        cout<<"Not a real circle\n";
        return;
    }
    float c = (*terms[0])[-1];
    float d = (*terms[1])[-1];
    float f = (*terms[2])[-1];
    if (f>=0){
        cout<<"Not a real circle\n";
        return;
    }
    float r = sqrt(-1*f/c);
    char c1 = min(v1,v2);
    char c2 = max(v1,v2);
    double pi = 3.14159265358979323846;
    std::cout << std::fixed << std::setprecision(2);
    cout<<"Area = " << pi*r*r <<" units^2."
        <<"Perimeter = " << 2*pi*r << " units."
        <<"Intercepts : "<<c1<<" = "<<r<<" , "<<c1<<" = "<<-1*r<<" , "<<c2<<" = "<<r<<" , "<<c2<<" = "<<-1*r<<endl;
}
