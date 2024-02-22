#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <sstream>
#include <cstddef>

/* ------------------------- DO NOT MODIFY THIS FILE ------------------------ */

//A cpp file is not needed for this class

template <class T>
class Node
{
    public:
    Node<T> *next;
    T data;
    Node(T data){
        this->data = data;
        this->next = NULL;
    };
    Node(T data, Node<T> *next){
        this->data = data;
        this->next = next;
    };
    ~Node(){
        this->next = NULL;
    };
};


#endif