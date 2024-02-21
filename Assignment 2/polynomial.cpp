#include "polynomial.h"
#include "term.h"

term** deepCopy(term** other, int num, int extra = 0){
    term** result = new term*[num+extra];

    for (int i = 0; i < num; i++)
        result[i] = new term(*other[i]);

    for (int i = num; i < (num+extra); i++)
        result[i] = NULL;

    return result;
}

void sort(term**& p, int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (*p[i] > *p[j])
                swap(*p[i],*p[j]);
}

term addCoefficients(term t1,term t2){
    int c = t1[-1] + t2[-1];
    int n = t1.getNumVariables();
    char* v = t1.getVariables();
    int* p = new int[n];
    for (int i = 0; i < n; i++)
        p[i] = t1[i];
    term result(c,n,v,p);
    delete[] p;
    return result;
}

void addTerm(int &numTerms, term** &terms, term* newTerm){
    term** poly = new term*[numTerms+1];
    for (int i = 0; i < numTerms; i++){
        poly[i] = new term(*terms[i]);
        delete terms[i];
    }
    delete[] terms;
    poly[numTerms] = new term(*newTerm);
    sort(poly,++numTerms);
    terms = poly;
}

void removeTerm(int &numTerms, term** &terms, int termIndex){
    term** poly = new term*[numTerms-1];
    for (int i = 0; i < termIndex; i++){
        poly[i] = new term(*terms[i]);
        delete terms[i];
    }
    delete terms[termIndex];        
    for (int i = termIndex+1; i < numTerms; i++){
        poly[i-1] = new term(*terms[i]);
        delete terms[i];
    }
    delete[] terms;
    sort(poly,--numTerms);
    terms = poly;
}

void polynomial::addOrRemoveTerm(term* t) {
    int index = termIndex(t);
    if (index == -1)
        addTerm(numTerms,terms,t);
    else{
        *terms[index] = addCoefficients(*terms[index],*t);
        if ((*terms[index])[-1] == 0)
            removeTerm(numTerms,terms,index);
    }
}

int polynomial::termIndex(term* t) const {
    for (int i = 0; i < numTerms; i++)
        if (*t == *terms[i])
            return i;
    return -1;
}

polynomial::polynomial() {
    terms = new term*[0];
    numTerms = 0;
}

polynomial::polynomial(term** t, int n) {
    terms = new term*[0];
    numTerms = 0;
    for (int i = 0; i < n; i++)
        addOrRemoveTerm(t[i]);
}

term getTerm(std::string& input) {
    bool neg = false;
    if (input.find("- ") == 0) {
        neg = true;
        input.erase(0,2);
    }
    if (input.find("+ ") == 0) {
        neg = false;
        input.erase(0,2);
    }
    size_t pPos = input.find(" + ");
    size_t mPos = input.find(" - ");
    size_t pos;

    if (pPos == std::string::npos && mPos == std::string::npos) {
        std::string result = input;
        input.clear();
        term t(result.c_str());
        if (neg) return !t;
        else return t;
    }

    if (pPos == std::string::npos) {
        pos = mPos;
    } else if (mPos == std::string::npos) {
        pos = pPos;
    } else {
        pos = std::min(pPos, mPos);
    }

    std::string result = input.substr(0, pos);
    input.erase(0, pos+1);

    term t(result.c_str());
    if (neg) return !t;
    else return t;
}

polynomial::polynomial(const char* input) {
    string in = input;
    terms = new term*[0];
    numTerms = 0; 
    while (in.length()!=0){
        term t = getTerm(in);
        addOrRemoveTerm(&t);
    }
}

polynomial::polynomial(const polynomial& other) {
    numTerms = other.numTerms;
    terms = deepCopy(other.terms,numTerms);
}

polynomial::polynomial(term t) {
    numTerms = 0;
    terms = new term*[0];
    addOrRemoveTerm(&t);
}

polynomial::~polynomial() {
    if (terms != NULL){
        for (int i = 0; i < numTerms; i++)
            if (terms[i] != NULL){
                delete terms[i];
                terms[i]=NULL;
            }                
        delete[] terms;
        terms = NULL;
    } 
}

// Member Functions
term** polynomial::getTerms() const {
    return terms;
}

int polynomial::getNumTerms() const {
    return numTerms;
}

polynomial& polynomial::operator=(const polynomial& other) {
    if (this == &other) return *this;

    if (terms != NULL){
        for (int i = 0; i < numTerms; i++)
            if (terms[i] != NULL){
                delete terms[i];
                terms[i]=NULL;
            }                
        delete[] terms;
        terms = NULL;
    } 

    numTerms = other.numTerms;
    terms = deepCopy(other.terms,numTerms);   

    return *this;
}

term* polynomial::operator[](int idx) const {
    if (idx >= 0 && idx < numTerms)
        return terms[idx];
    return NULL;
}

term* polynomial::operator[](int idx) {
    if (idx >= 0 && idx < numTerms)
        return terms[idx];
    return NULL;
}

ostream& operator<<(ostream& os, const polynomial& p) {
    if (p.numTerms == 0)
        os<<"0"<<endl;
    else{
        for (int i = 0; i < p.numTerms-1; i++)
            os << ~(*p.terms[i]) << " + ";
        os << ~(*p.terms[p.numTerms-1]) << endl;   
    }         
    return os;
}