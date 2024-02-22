#include "bulk.h"
#include <iostream>
#include <iomanip>
#include <sstream>

bulk::bulk(std::string n, int bN, int v, int a, float dP, int dA) : product(n, bN, v, a) {
    discountPercentage = dP;
    discountAmount = dA;
}

bulk::~bulk() {}

float bulk::price(std::string s) {
    std::istringstream iss(s);
    int q;
    iss >> q;
    float totalPrice =(q/discountAmount) *  discountAmount * value * (1.00 - discountPercentage);
    totalPrice += q % discountAmount * value;
    return totalPrice/1.00;
}

void bulk::print() {
    std::cout   <<"bulk"
                <<"{"<<getBarcode()<<"}"
                <<"{"<<name<<"}"
                <<"{R"<<value<<"}"
                <<"{"<<amount<<"}"
                <<"{"<<std::fixed << std::setprecision(2) << discountPercentage * 100.0 <<"%}"
                <<"{"<<discountAmount<<"}\n";
}
