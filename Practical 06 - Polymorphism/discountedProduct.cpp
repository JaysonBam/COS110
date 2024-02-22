#include "discountedProduct.h"
#include <iostream>
#include <iomanip>
#include <sstream>

discountedProduct::discountedProduct(std::string n, int bN, int v, int a, float d) : product(n, bN, v, a) {
    discount = d;
}

discountedProduct::~discountedProduct() {
    //product::~product();
}

float discountedProduct::price(std::string s) {
    std::istringstream iss(s);
    int q;
    iss >> q;
    float totalPrice = q * value * (1.00 - discount);
    return totalPrice;
}

void discountedProduct::print(){
    std::cout   <<"discountedProduct"
                <<"{"<<getBarcode()<<"}"
                <<"{"<<name<<"}"
                <<"{R"<<value<<"}"
                <<"{"<<amount<<"}"
                <<"{"<<std::fixed << std::setprecision(2) << discount * 100.0 <<"%}\n";
}
