#ifndef DISCOUNTEDPRODUCT_H
#define DISCOUNTEDPRODUCT_H

#include "product.h"

class discountedProduct : public product {
private:
    float discount;
public:
    discountedProduct(std::string n, int bN, int v, int a, float d);
    ~discountedProduct();
    float price(std::string s);
    void print();
};

#endif
