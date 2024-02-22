#ifndef STACK_H
#define STACK_H


/* ------------------------- DO NOT MODIFY THIS FILE ------------------------ */

#include "Node.h"

template <class T>
class Stack
{
    private:
    Node<T>* top;
    public:
    Stack();
    Stack(const Stack<T>& other);
    ~Stack();
    void push(T data);
    T pop();
    const T peek() const;
    bool isEmpty() const;
};

#endif