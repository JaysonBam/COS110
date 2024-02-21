#include "term.h"

void sort(char*& v, int*& p, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (v[i] > v[j]){
                swap(v[i],v[j]);
                swap(p[i],p[j]);
            }
}

int* deepCopy(int* other, int num,int extra = 0){
    int* result = new int[num+extra];
    for (int i = 0; i < num; i++){
        result[i] = other[i];
    }
    return result;
}

char* deepCopy(char* other, int num,int extra = 0){
    char* result = new char[num+extra];
    for (int i = 0; i < num; i++){
        result[i] = other[i];
    }
    return result;
}


void term::addVariable(char var, int pow){
    //return if not valid
    if (pow <= 0 || coefficient == 0) 
        return;

    //else increase power if found
    for (int i = 0; i < numVariables; i++)
        if (var == variables[i]){
                powers[i] += pow;
                return;
        }

    //else add in alphabetical order
    char* tempVar = deepCopy(variables, numVariables,1);
    int* tempPow  = deepCopy(powers   , numVariables,1);
    numVariables++;
    tempVar[numVariables-1] = var;
    tempPow[numVariables-1] = pow;
    if (variables!=NULL) delete[] variables;
    if (powers!=NULL) delete[] powers;
    variables=tempVar;
    powers=tempPow;
    sort(variables,powers,numVariables);
}

void term::removeVariable(char var) {
    int index = -1;
    for (int i = 0; i < numVariables; i++) {
        if (variables[i] == var) {
            index = i;
            break;
        }
    }

    if (index == -1)
        return;

    char* newVariables = new char[numVariables - 1];
    int* newPowers = new int[numVariables - 1];

    int j = 0;
    for (int i = 0; i < numVariables; i++) {
        if (i != index) {
            newVariables[j] = variables[i];
            newPowers[j] = powers[i];
            j++;
        }
    }

    delete[] variables;
    delete[] powers;
    variables = newVariables;
    powers = newPowers;
    numVariables--;
}

term::term(){
    coefficient = 1;
    numVariables = 0;
    variables = NULL;
    powers = NULL;
    variables = new char[0];
    powers = new int[0];    
}

term::term(const term& other){
    coefficient = other.coefficient;
    numVariables = other.numVariables;
    variables = deepCopy(other.variables,numVariables);
    powers = deepCopy(other.powers,numVariables);
}

term::term(int c, int n, char* v, int* p){
    coefficient = c;
    numVariables = 0;
    powers = new int[0];
    variables = new char[0];
    for (int i = 0; i < n; i++)
        addVariable(v[i],p[i]);
}

string getSegment(string& input){   //get 0 to * or to end
    size_t asteriskPos = input.find('*');
    string result;
    if (asteriskPos != std::string::npos) {
        result = input.substr(0, asteriskPos);
        input.erase(0, asteriskPos + 1);
    } else {
        result = input;
        input = "";
    }
    return result;
}

int getCoefficient(string& input) {
    // Get sign
    int sign = 1;
    if (input[0] == '-') {
        sign = -1;
        input.erase(0, 1);
    } else if (input[0] == '+') {
        input.erase(0, 1);
    }

    // Get coefficient
    int c;
    if (!isdigit(input[0])) {
        c = 1;
    } else {
        c = atoi(getSegment(input).c_str());
    }

    return sign * c;
}

term::term(const char* input){
    string in = input;
    coefficient = 1;
    numVariables = 0;
    variables = new char[0];
    powers = new int[0]; 

    coefficient = getCoefficient(in);
    while (in.length()!=0){
        char base;
        int power;
        string s = getSegment(in);
        base = s[0];
        size_t asteriskPos = s.find('^');
        if (asteriskPos != std::string::npos) {
            s.erase(0, asteriskPos + 1);
            power = atoi(s.c_str());
        } else {
            power = 1;
        }
        addVariable(base,power);
    }       

}

term& term::operator=(const term& other){
    if (this == &other) return *this;

    delete[] variables;
    delete[] powers;

    coefficient = other.coefficient;
    numVariables = other.numVariables;
    variables = deepCopy(other.variables,other.numVariables);
    powers = deepCopy(other.powers,other.numVariables);

    return *this;
}

term::~term(){
    delete[] variables;
    delete[] powers;
}

char* term::getVariables() const{
    return variables;
}
    
int term::getNumVariables() const{
    return numVariables;
}

int term::getDegree() const{
    int result = 0;
    for (int i = 0; i < numVariables; i++)
        result += powers[i];
    return result;
}

int term::getVarIndex(char var) const{
    for (int i = 0; i < numVariables; i++)
        if (variables[i] == var)
            return i;
    return -1;
}

string term::operator~() const{
    std::stringstream ss;

    if (numVariables == 0) {
        if (coefficient == -1) {
            ss << "-1";
        } else if (coefficient == 1) {
            ss << "1";
        } else {
            ss << coefficient;
        }
    } else {
        if (coefficient == -1) {
            ss << "-";
        } else if (coefficient != 1) {
            ss << coefficient << "*";
        }
    }

    
    for (int i = 0; i < numVariables; i++) {
        if (i > 0) ss << "*"; 
        if (powers[i] == 1) 
            ss << variables[i];
        else 
            ss << variables[i] << "^" << powers[i];
    }

    return ss.str();
}

ostream& operator<<(ostream& os, const term& t){
    os << ~t << std::endl;
    return os;
}

istream& operator>>(istream& is, term& t) {
    string s;
    is >> s;
    term temp(s.c_str());
    t = temp;
    return is;
}


const term term::operator*(const term& other) const {
    term result;
    result.coefficient = coefficient*other.coefficient;
    for (int i = 0; i < numVariables; i++) {
        result.addVariable(variables[i], powers[i]);
    }

    for (int i = 0; i < other.numVariables; i++) {
        result.addVariable(other.variables[i], other.powers[i]);
    }

    return result;
}

    
term& term::operator*=(const term& other){
    *this = *this * other;
    return *this;
}

const term term::operator()(char* vars, int* vals, int numVals) const{
    term result(*this);
    for (int i = 0; i < numVals; i++){
        int index = getVarIndex(vars[i]);
        if (index != -1){
            result.coefficient*=pow(vals[i],powers[index]);
            result.removeVariable(vars[i]);
        }
    }
    if (result.coefficient == 0) {
        term temp("0");
        result = temp;
    }

    return result;
}



const term term::operator()(string inp) const{
    term result(*this);
    int size = 0;
    for (int i = 0; i < inp.length(); i++)
        if (inp[i]=='=') size++;
    char* var = new char[size];
    int*  val = new  int[size];

    for (int i = 0; i < size; i++){
        var[i] = inp[0];
        inp.erase(0,2);
        val[i] = atoi(inp.substr(0,inp.find(' ')).c_str());
        inp.erase(0,inp.find(' ')+1);
    }
    result = result(var,val,size);
    delete[] var;
    delete[] val;
    return result;
}

bool term::operator==(const term& other) const{
    if (numVariables!=other.numVariables) return false;
    bool result = true;
    for (int i = 0; i < numVariables; i++)
        if (variables[i]!=other.variables[i] || powers[i]!=other.powers[i]) result = false;
    return result;
}
    
bool term::operator<(const term& rhs) const {
    term lhs(*this);
    if (lhs == rhs) {return false;}
    /*1*/if (lhs.numVariables == 0) {return false;}
    /*2*/if (rhs.numVariables == 0) {return true;}
    /*3*/
    int loop = min(lhs.numVariables,rhs.numVariables);
    for (int i = 0; i < loop; i++) {
        if (lhs.variables[i] == rhs.variables[i]) {
            if (lhs.powers[i] == rhs.powers[i]) {} 
            else {return (lhs.powers[i] > rhs.powers[i]);}
        } 
        else {
            return !(lhs.variables[i] > rhs.variables[i]);
        }
    }

    /*4*/return (lhs.numVariables < rhs.numVariables);
}

    
bool term::operator>(const term& rhs) const {
    term lhs(*this);
    if (lhs == rhs) {return false;}
    /*1*/if (lhs.numVariables == 0) {return true;}
    /*2*/if (rhs.numVariables == 0) {return false;}
    /*3*/
    int loop = min(lhs.numVariables,rhs.numVariables);

    for (int i = 0; i < loop; i++) {
        if (lhs.variables[i] == rhs.variables[i]) {
            if (lhs.powers[i] == rhs.powers[i]) {} 
            else {return !(lhs.powers[i] > rhs.powers[i]);}
        }
        else {return (lhs.variables[i] > rhs.variables[i]);}
    }

    /*4*/return !(lhs.numVariables < rhs.numVariables);
}


int& term::operator[](int idx){
    if (idx >= 0 && idx < numVariables) return powers[idx];
    else                                return coefficient;
}

const term term::operator!() const{
    term result(*this);
    result.coefficient*=-1;
    return result;
}