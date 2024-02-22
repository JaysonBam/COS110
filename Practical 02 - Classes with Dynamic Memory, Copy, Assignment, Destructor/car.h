#ifndef CAR_H
#define CAR_H

#include <string>
#include <sstream>
#include "accessory.h"
#include "engine.h"

class Car {
private:
    std::string name;
    int numAccessories;
    Engine* engine;
    Accessory** accessories;
public:
    Car(std::string, int);
    Car(const Car&);
    ~Car();
    Car& operator=(const Car&);
    double getPrice();
    std::string getName();
    int getNumAccessories();
    Accessory** getAccessoriesArr();
    Engine* getEngine();
    bool addAccessory(Accessory*);
    void setEngine(Engine*);
    std::string getDetails();
};

#endif // ACCESSORY_H
