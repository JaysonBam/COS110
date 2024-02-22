#include "product.h"
#include <iostream>
#include <iomanip>
#include <sstream>

product::product(std::string n, int bN, int v, int a) : item(n, bN) {
    value = v;
    amount = a;
}

product::~product() {}

void product::buy(std::string s) {
    std::istringstream iss(s);
    int q;
    iss >> q;    
    if (q > amount) q = amount;
    std::ostringstream newS;
    newS << q;
    std::cout   << "Bought"
                <<"{"<<q<<"}"
                <<"{"<<name<<"}"
                <<"{R"<< std::fixed << std::setprecision(2) << price(newS.str()) <<"}\n";
    amount -= q;
}

float product::price(std::string s) {
    std::istringstream iss(s);
    int q;
    iss >> q;
    float totalPrice = q * value;
    return totalPrice;
}


void product::print(){
    std::cout   <<"product"
                <<"{"<<getBarcode()<<"}"
                <<"{"<<name<<"}"
                <<"{R"<<value<<"}"
                <<"{"<<amount<<"}\n";
}