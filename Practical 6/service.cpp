#include "service.h"
#include <iostream>
#include <iomanip>
#include <sstream>

service::service(std::string n, int bN, int r, char p) : item(n, bN) {
    rate = r;
    period = p;
}

service::~service() {}

float getTime(std::string s){
    std::string sTime = s.substr(0,s.find(' '));
    std::istringstream iss(sTime);
    float result;
    iss >> result; 
    return result;   
}

char getPeriod(std::string s){
    s.erase(0,s.find(' ')+1);
    char result = s[0];
    std::string p = "hdwm";
    if (p.find(result) == std::string::npos)  
        result = 'y';
    return result;  
}

float hourCon(char c){
    if (c == 'y') return 8064.00;
    if (c == 'm') return 672.00;
    if (c == 'w') return 168.00;
    if (c == 'd') return 24.00; 
    if (c == 'h') return 1.00;
    return 8064.00;
}

float convert(char from, char to){
    float result = 1.00;
    result *= hourCon(from);
    result /= hourCon(to);
    return result;
}

static std::string getPName(char c){
    if (c == 'y') return "year";
    if (c == 'm') return "month";
    if (c == 'w') return "week";
    if (c == 'd') return "day"; 
    if (c == 'h') return "hour";
    return "year";
}

void service::buy(std::string s) {
    int t = getTime(s);
    char p = getPeriod(s);
    std::cout   << "Bought"
                <<"{"<<t<<getPName(p)<<"s}"
                <<"{"<<name<<"}"
                <<"{R"<< std::fixed << std::setprecision(2) << price(s)<<"}\n";
 
}

float service::price(std::string s) {
    float t = getTime(s);
    char p = getPeriod(s);
    float newTime = t*convert(p,period);
    float price = rate * newTime;
    return price;
}

void service::print(){
    std::cout   <<"service"
                <<"{"<<getBarcode()<<"}"
                <<"{"<<name<<"}"
                <<"{R"<<rate<<"/"<<getPName(period)<<"}\n";
}
