#include "accessory.h"
#include <string>
#include <sstream>

Accessory::Accessory(std::string name, std::string description, double price){
    this->description = description;
    this->name = name;
    this->price = price;
}

Accessory::Accessory(const Accessory& other){
    this->description = other.description;
    this->name = other.name;
    this->price = other.price;
}

Accessory::~Accessory(){}

std::string Accessory::getDetails(){
    std::stringstream stringPrice;
    stringPrice << price;
    return "Accessory Name: " + name + "\nDescription: " + description + "\nPrice: " + stringPrice.str();
}

double Accessory::getPrice(){
    return price;
}