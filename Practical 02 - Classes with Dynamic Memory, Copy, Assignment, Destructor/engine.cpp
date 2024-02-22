#include "engine.h"
#include <sstream>
#include <string>

Engine::Engine(std::string name,int horsepower,int displacement,double price){
    this->name = name;
    this->horsepower = horsepower;
    this->displacement = displacement;
    this->price = price;
}
    
Engine::Engine(const Engine& other){
    this->name = other.name;
    this->horsepower = other.horsepower;
    this->displacement = other.displacement;
    this->price = other.price;
}

Engine::~Engine(){}

std::string Engine::getDetails(){
    std::stringstream sHorsepower,sDisplacent,sPrice;
    sPrice << price;
    sHorsepower << horsepower;
    sDisplacent << displacement;
    return "Engine name: " + name + "\nHorsepower: " + sHorsepower.str() + "\nDisplacement: " + sDisplacent.str() + "\nPrice: " + sPrice.str();
}

double Engine::getPrice(){
    return price;
}