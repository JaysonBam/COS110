#include "labor.h"
#include <iostream>
#include <iomanip>
#include <sstream>

labor::labor(std::string n, int bN, int r, char p, int* wR, int num) : service(n, bN, r, p) {
    numWorkers = num;
    workerRates = new int[num];
    for (int i = 0; i < num; i++)
        workerRates[i] = wR[i];
}

labor::~labor() {
    if (workerRates != NULL){
        delete[] workerRates;
        workerRates = NULL;
    }
}

float labor::price(std::string s) {
    float price = service::price(s);
    float result = 0.00;
    for (int i = 0; i < numWorkers; i++)
        result += price*workerRates[i];
    return result;
}

static std::string getPName2(char c){
    if (c == 'y') return "year";
    if (c == 'm') return "month";
    if (c == 'w') return "week";
    if (c == 'd') return "day"; 
    if (c == 'h') return "hour";
    return "year";
}

void labor::print(){
    std::cout   <<"labor"
                <<"{"<<getBarcode()<<"}"
                <<"{"<<name<<"}"
                <<"{R"<<rate<<"/"<<getPName2(period)<<"}"
                <<"{[";
    for (int i = 0; i < (numWorkers-1); i++)
        std::cout<<workerRates[i]<<",";
    std::cout<<workerRates[numWorkers-1]<<"]}\n";
}
