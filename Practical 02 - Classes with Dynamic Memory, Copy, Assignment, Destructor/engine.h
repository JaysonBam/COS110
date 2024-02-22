#ifndef ENGINE_H
#define ENGINE_H

#include <string>


class Engine {
private:
    std::string name;
    int horsepower;
    int displacement;
    double price;
public:
    Engine(std::string, int, int, double);
    Engine(const Engine&);
    ~Engine();
    std::string getDetails();
    double getPrice();
};

#endif // ACCESSORY_H
