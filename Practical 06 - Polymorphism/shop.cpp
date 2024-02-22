#include "shop.h"
#include <iostream>
#include <iomanip>
#include <sstream>

shop::shop(){
    numItems = 0;
    items = new item*[0];
}

shop::~shop() {
    if (items!=NULL){
        for (int i = 0; i < numItems; i++)
            if (items[i] != NULL){
                delete items[i];
                items[i]=NULL;
            }
        delete[] items;
        items = NULL;
    }
}

int shop::itemIndex(std::string n){
    for (int i = 0; i < numItems; i++)
        if (items[i]->getName() == n)
            return i;
    return -1;
}

void shop::addItem(item* i) {
    if (itemIndex(i->getName())!=-1){
        std::cout<<"Item already in shop\n";
        return;
    } 
    item** temp = new item*[numItems+1];
    for (int i = 0; i < numItems; i++)
        temp[i] = items[i];
    temp[numItems] = i;
    delete[] items;
    items = temp;
    numItems++;
}

void shop::addItems(item** i, int n) {
    for (int j = 0; j < n; j++)
        addItem(i[j]);
}



void shop::buyItems(std::string s) {
    float total = 0;
    while (!s.empty()) {
        std::string name = s.substr(0, s.find(':'));
            s.erase(0, s.find(':') + 1);
        std::string par = s.substr(0, s.find('|'));
            s.erase(0, s.find('|') + 1);

        int idx = itemIndex(name);

        if (idx == -1) {
            std::cout << "Couldn't find " << name << std::endl;
        } else {
            items[idx]->buy(par);
            total += items[idx]->price(par);
        }
    }
    std::cout << "Total: R " << std::fixed << std::setprecision(2) << total << std::endl;
}

void shop::printItems(){
    for (int i = 0; i < numItems; i++)
        items[i]->print();
}

void shop::removeItem(std::string s) {
    int idx = itemIndex(s);
    if (idx == -1) {
        std::cout << "Item not found" << std::endl;
    } else {
        item** temp = new item*[numItems - 1];
        for (int i = 0; i < idx; i++) {
            temp[i] = items[i];
        }
        for (int i = idx + 1; i < numItems; i++) {
            temp[i - 1] = items[i];
        }
        delete items[idx];
        delete[] items;
        items = temp;
        numItems--;
    }
}

