#ifndef ACCESSORY_H
#define ACCESSORY_H

#include <string>

class Accessory {
private:
    std::string name;
    std::string description;
    double price;
public:
    Accessory(std::string, std::string, double);
    Accessory(const Accessory&);
    ~Accessory();
    std::string getDetails();
    double getPrice();
};

#endif // ACCESSORY_H
