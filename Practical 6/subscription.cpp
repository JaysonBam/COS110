#include "subscription.h"
#include <iostream>
#include <iomanip>
#include <sstream>

subscription::subscription(std::string n, int bN, int r, char p, float d) : service(n, bN, r, p) {
    yearDiscount = d;
}

subscription::~subscription() {
    //service::~service();
}

char getPeriod3(std::string s){
    s.erase(0,s.find(' ')+1);
    char result = s[0];
    std::string p = "hdwm";
    if (p.find(result) == std::string::npos)  
        result = 'y';
    return result;  
}

float subscription::price(std::string s) {
    float result = service::price(s);
    if (getPeriod3(s) == 'y')
        result*= (1 - yearDiscount);
    return result;
}

static std::string getPName3(char c){
    if (c == 'y') return "year";
    if (c == 'm') return "month";
    if (c == 'w') return "week";
    if (c == 'd') return "day"; 
    if (c == 'h') return "hour";
    return "year";
}

void subscription::print(){
    std::cout   <<"subscription"
                <<"{"<<getBarcode()<<"}"
                <<"{"<<name<<"}"
                <<"{R"<<rate<<"/"<<getPName3(period)<<"}"
                <<"{"<<std::fixed << std::setprecision(2) << yearDiscount * 100.0 <<"%}\n";
}
