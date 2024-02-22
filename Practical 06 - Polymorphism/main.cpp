#include <iostream>
#include <string>
#include "item.h"
#include "product.h"
#include "service.h"
#include "bulk.h"
#include "discountedProduct.h"
#include "labor.h"
#include "subscription.h"
#include "shop.h"

void outputTest(){
        item **items = new item *[6];
    items[0] = new product("productName", 0, 5, 5);
    items[1] = new bulk("bulkName", 0, 5, 5, 0.1, 8);
    items[2] = new discountedProduct("discountedProductName", 0, 5, 5, 0.1);

    items[3] = new service("serviceName", 0, 10, 'y');
    items[4] = new subscription("subscriptionName", 0, 10, 'y', 0.1);
    int *workers = new int[1];
    workers[0] = 10;
    items[5] = new labor("laborName", 0, 10, 'y', workers, 1);
    delete[] workers;

    for (int i = 0; i < 6; i++) {
        items[i]->print();
    }

    for (int i = 0; i < 3; i++) {
        items[i]->buy("5");
    }

    for (int i = 3; i < 6; i++) {
        items[i]->buy("5 w");
    }

    for (int i = 0; i < 6; i++) {
        delete items[i];
    }
    delete[] items;
}

void testService(){
    service Netflix("netflix",69,100,'k');
    Netflix.buy("10 h");
    Netflix.buy("2 j");
    Netflix.print();

    subscription Netflix2("netflix",69,100,'k',0.1);
    Netflix2.buy("10 h");
    Netflix2.buy("2 j");
    Netflix2.print();   

    int* w = new int[1];
    w[0]= 1;
    labor Netflix1("netflix",69,100,'k',w,1);
    Netflix1.buy("10 h");
    Netflix1.buy("2 j");
    Netflix1.print(); 
}

int main(){
    testService();
    outputTest();
    std::cout<<"------------------------------------------------------\n";
    shop spaza;
    int barcode = 100;
    item* i1 = new product("bannana",barcode++,7,50);
    item* i2 = new product("grape" ,barcode++,26,50);
    item** items = new item*[2];
    items[0] = i1;
    items[1] = i2;
    spaza.addItems(items,2);
    spaza.addItem(i1);
    delete[] items;
    spaza.addItem(new bulk("apples", barcode++,10,50,0.1,8));
    spaza.addItem(new discountedProduct("sweet",barcode++,12,50,0.2));

    spaza.buyItems("bannana:10|grape:70|choclate:9|apples:20|sweet:15|sweet:40|");

    std::cout<<std::endl;
    shop s;
    int* workers = new int[3];
    workers[0]=1;
    workers[1]=2;
    workers[2]=3;
    s.addItem(new service("Pool cleaning",barcode++,200,'d'));
    s.addItem(new labor("Building",barcode++,10,'h',workers,3));
    s.addItem(new subscription("Netflix",barcode++,200,'m',0.25));

    s.buyItems("Pool cleaning:10 h|Building:5 h|Netflix:12 m|Netflix:1 k|");

    spaza.printItems();
    s.printItems();
    spaza.removeItem("grape");
    spaza.removeItem("choclate");
    delete[] workers;
    return 0;
}