#ifndef SHOP_H
#define SHOP_H

#include "item.h"

class shop {
private:
    item** items;
    int numItems;
public:
    shop();
    ~shop();
    int itemIndex(std::string n);
    void addItem(item* i);
    void addItems(item** i, int n);
    void buyItems(std::string s);
    void printItems();
    void removeItem(std::string s);
};

#endif