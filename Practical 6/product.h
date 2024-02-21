#ifndef PRODUCT_H
#define PRODUCT_H

#include "item.h"

class product : public item {
protected:
    int value;
    int amount;
public:
    product(std::string n, int bN, int v, int a);
    ~product();
    void buy(std::string s);
    float price(std::string s);
    void print();
};

#endif
