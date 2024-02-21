#ifndef NODE_H
#define NODE_H

class node {
private:
    node* prev;
    node* next;
    int data;

public:
    node(int val);
    ~node();
    void destroyList();
    bool contains(int val);
    void insert(int val);
    void insert(node* n);
    void print();
    int length();
    node* remove(int val);
    node* head();
    node* tail();
};

#endif
