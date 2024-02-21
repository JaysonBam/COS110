#ifndef SERVICE_H
#define SERVICE_H

#include "item.h"

class service : public item {
protected:
    int rate;
    char period;
public:
    service(std::string n, int bN, int r, char p);
    ~service();
    void buy(std::string s);
    float price(std::string s);
    void print();
};

#endif