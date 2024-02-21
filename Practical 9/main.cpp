/*
Output for this main is inside output.txt
Note that output.txt is what my program prints when running this main, thus you should get exactly the same output as the textfile
*/
#include "node.h"
#include <iostream>

int main() {
    node* list1 = new node(2);
    list1->insert(4);
    list1->insert(6);
    list1->insert(8);
    list1->insert(10);

    node* list2 = new node(5);
    list2->insert(1);
    list2->insert(3);
    list2->insert(7);
    list2->insert(9);

   list1->print();
   list2->print();

    list1->insert(list2);
    list1->print();
    list2->print();

    list1->contains(1);
    list1->contains(10);
    list1->contains(13);

    //list1 = list1->tail();
    //list1->remove(13);
    node* r = list1->remove(6);
   // delete r;
    //std::cout<<list1->length()<<":";
    list1->print();
    list2->print();

    return 0;
}