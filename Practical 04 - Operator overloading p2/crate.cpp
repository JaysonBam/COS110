#include "crate.h"
#include <iomanip>
#include <sstream>
#include <iostream>

crate::crate(){
    name = "empty";
    amount = 0;
    price = 0;
}

crate::crate(std::string name, int amount, float price){
    this->name = name;
    this->amount = amount;
    this->price = price;
}

crate::crate(const crate& other){
    name = other.name;
    amount = other.amount;
    price = other.price;  
}

crate::crate(std::string s){
    name = "empty";
    amount = 0;
    price = 0;
    *this|s;
}

void crate::setName(std::string name){
    this->name = name;
}
  
void crate::setAmount(int amount){
    this->amount = amount;
}

void crate::setPrice(float price){
    this->price = price;
}

std::string crate::getName(){
    return name;
}

int crate::getAmount(){
    return amount;
}
  
float crate::getPrice(){
    return price;
}

float crate::getValue(){
    return amount*price;
}

std::ostream& operator<<(std::ostream& os, crate& c) {
    os << std::left << std::setw(50) << c.name;
    os << std::left << std::setw(10) << c.amount;
    os << std::left << std::setw(2)  << "R ";
    os << std::left << std::setw(8)  << std::fixed << std::setprecision(2) << c.price;
    os << std::left << std::setw(2)  << "R ";
    os << std::left << std::setw(8)  << std::fixed << std::setprecision(2) << c.getValue();
    os << std::endl;
  return os;
}

  
std::istream& operator>>(std::istream& is, crate& c){
    std::string s;
    std::getline(is,s);
    c|s;
    return is;
}
  
crate& crate::operator|(std::string input){
    std::string name,amount,price;
    name = input.substr(0,input.find("|"));
    input.erase(0,input.find("|")+1);
    amount = input.substr(0,input.find("|"));
    input.erase(0,input.find("|")+1);
    price = input;

    if (name.length()!=0) 
    {
        this->name = name;
    }

    if (amount.length()!=0) 
    {
        std::stringstream sAmount(amount);
        sAmount >> this->amount;
    }
    
    if (price.length())
    {
        std::stringstream sPrice(price);
        sPrice >> this->price;
    }

    return *this;
}

crate& crate::operator++() {
    amount++;
    return *this;
}
  
crate crate::operator++(int dummy) {
    crate temp(*this); 
    amount++;          
    return temp;       
}
  
crate& crate::operator+=(int a){
    amount += a;
    return *this;
}
  
crate& crate::operator-=(int a){
    amount -= a;
    if (amount<=0){
        name = "empty";
        amount = 0;
        price = 0;
    }
    return *this;
}

bool crate::operator==(crate& other){
    return (name==other.name && price==other.price);
}
  
bool crate::operator<=(crate& other){
    return (name<=other.name);
}

bool crate::operator>=(crate& other){
    return (name>=other.name);
}
  
bool crate::operator<(crate& other){
    return (getValue()<=other.getValue());
}

bool crate::operator>(crate& other){
    return (getValue()>=other.getValue());
}