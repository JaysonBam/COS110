#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H

#include "service.h"

class subscription : public service {
private:
    float yearDiscount;
public:
    subscription(std::string n, int bN, int r, char p, float d);
    ~subscription();
    float price(std::string s);
    void print();
};

#endif
