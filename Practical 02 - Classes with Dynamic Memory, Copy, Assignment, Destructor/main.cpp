#include <iostream>
#include <string>
#include "engine.h"
#include "car.h"
#include "accessory.h"


int main() {
    Accessory* acc1 = new Accessory("Roof Rack", "External cargo holder for bikes, gear", 500.0);
    Accessory* acc2 = new Accessory("Seat Covers", "Protect seats, personalize style", 100.0);
    Accessory* acc3 = new Accessory("Phone Mount","Secure phone holder for hands-free use",20.50);

    Engine* V6 = new Engine("V6 Engine", 300, 3500, 2000.0);
    Engine* V8 = new Engine("V8, twin-turbo Engine", 785, 4500, 6000.0);

    Car* E_Class = new Car("Mercedes-Benz E-Class", 3);
    E_Class->setEngine(V6);
    E_Class->addAccessory(acc1);
    E_Class->addAccessory(acc2);

    Car* E_Class_V8 = new Car("Car 1",4);
    *E_Class_V8 = *E_Class;
    E_Class_V8->setEngine(V8);
    E_Class_V8->setEngine(V8);
    E_Class_V8->setEngine(NULL);
    E_Class_V8->addAccessory(acc3);

    std::cout <<"Car 1--------------------------\n"<< E_Class->getDetails() << std::endl;
    std::cout <<"Car 2--------------------------\n"<< E_Class_V8->getDetails() << std::endl;

    std::cout <<"Car 2 Summary------------------\n";
    std::cout <<"Name: "<< E_Class_V8->getName() << std::endl;
    std::cout <<"Engine: R"<< E_Class_V8->getEngine()->getPrice() << std::endl;
    int size = E_Class_V8->getNumAccessories();
    for (int i=0;i<3;i++)
        std::cout <<"Accessory "<<i+1<<" : R"<< E_Class_V8->getAccessoriesArr()[i]->getPrice()<< std::endl;

    delete E_Class; E_Class = NULL;
    delete E_Class_V8; E_Class_V8 = NULL;
    
    return 0;
}
