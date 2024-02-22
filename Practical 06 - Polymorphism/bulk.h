#ifndef BULK_H
#define BULK_H

#include "product.h"

class bulk : public product {
private:
    float discountPercentage;
    int discountAmount;
public:
    bulk(std::string n, int bN, int v, int a, float dP, int dA);
    ~bulk();
    float price(std::string s);
    void print();
};

#endif
