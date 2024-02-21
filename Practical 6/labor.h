#ifndef LABOR_H
#define LABOR_H

#include "service.h"

class labor : public service {
private:
    int* workerRates;
    int numWorkers;
public:
    labor(std::string n, int bN, int r, char p, int* wR, int num);
    ~labor();
    float price(std::string s);
    void print();
};

#endif