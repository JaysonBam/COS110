#include <iostream>
#include <string>
#include <sstream>
#include "accessory.h"
#include "engine.h"
#include "car.h"

int NumOfOpenAccessories(Accessory** accessories, int size) {
    int result = 0;
    if (accessories != NULL) {
        for (int i = 0; i < size; i++) {
            if (accessories[i] == NULL) result++;
        }
    }
    return result;
}

static Engine* CopyEngine(const Engine* other) {
    Engine* result;
    if (other == NULL) result = NULL;
    else result = new Engine(*other);
    return result;
}

Accessory** CopyAccessories(Accessory** other, int size) {
    Accessory** result;
    if (other == NULL) result = NULL;
    else {
        result = new Accessory*[size];
        for (int i = 0; i < size; i++) {
            if (other[i] == NULL) result[i] = NULL;
            else result[i] = new Accessory(*other[i]);
        }
    }
    return result;
}

Car::Car(std::string name,int numAccessories){
    this->name = name;
    this->numAccessories = numAccessories;
    if (numAccessories <= 0){
        this->numAccessories = 0;
        this->accessories = NULL;
    }
    else{
        this->accessories = new Accessory*[numAccessories];
        for (int i = 0; i < numAccessories; i++)
            this->accessories[i] = NULL;
    }
    this->engine = NULL;
}

Car::Car(const Car& other){
    this->name = other.name;
    this->numAccessories = other.numAccessories;
    this->engine = CopyEngine(other.engine);
    this->accessories = CopyAccessories(other.accessories,numAccessories);
}

Car::~Car(){
    if (engine != NULL){
        delete engine;
        engine = NULL;
    }
    if (accessories != NULL){
        for (int i=0;i<numAccessories;i++){
            if (accessories[i] != NULL){
                delete accessories[i];
                accessories[i] = NULL;
            }
        }
        delete[] accessories;
        accessories = NULL;        
    } 
}

Car& Car::operator=(const Car& other){
    if (&other == this) return *this;

//delete this data
    if (engine != NULL){
        delete engine;
        engine = NULL;
    }

    if (accessories != NULL){
        for (int i=0;i<numAccessories;i++){
            if (accessories[i] != NULL){
                delete accessories[i];
                accessories[i] = NULL;
            }
        }
        delete[] accessories;
        accessories = NULL;        
    }
//allocate new data to this
    this->name = other.name;
    this->numAccessories = other.numAccessories;
    this->engine = CopyEngine(other.engine);
    this->accessories = CopyAccessories(other.accessories,numAccessories);

    return *this;
}

double Car::getPrice(){
    double result = 0;
    if (accessories != NULL){
    for (int i = 0; i < numAccessories; i++)
        if (accessories[i]!=NULL)
            result += accessories[i]->getPrice();
    }
    if (engine != NULL)
        result += engine->getPrice();
    return result;
}

bool Car::addAccessory(Accessory* accessory){    
    int openAccessories = NumOfOpenAccessories(accessories,numAccessories);  
    int index = numAccessories-openAccessories;    
    if (openAccessories == 0) return false;   
    accessories[index] = accessory;
    return true;
}

void Car::setEngine(Engine* engine){
    if (engine == this->engine || engine == NULL) 
        return;
    else
    {
        delete this->engine;
        this->engine = engine ;
    }
    
}

std::string Car::getDetails(){
    std::string result = "";
    result += "Details:\n";
    result += "Car: " + name + "\n";
    std::stringstream sPrice;;
    sPrice << getPrice();
    result += "Price: " + sPrice.str();

    if (engine != NULL){
        result += "\n" + engine->getDetails();
    }
    if (accessories != NULL){
        int size = numAccessories-NumOfOpenAccessories(accessories,numAccessories);
        for (int i = 0; i < size ;i++)
            if (accessories[i]!=NULL)
                result += "\n" + accessories[i]->getDetails();
    }
    return result;

}

std::string Car::getName(){
    return name;
}

int Car::getNumAccessories(){
    return numAccessories;
}

Accessory** Car::getAccessoriesArr(){
    return accessories;
}

Engine* Car::getEngine(){
    return engine;
}

