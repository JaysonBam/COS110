#ifndef QUEUE_H
#define QUEUE_H

/* ------------------------- DO NOT MODIFY THIS FILE ------------------------ */

#include "Node.h"
#include <iostream>
#include <cstddef>

template <class T>
class Queue
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    Queue();
    Queue(const Queue<T> &other);
    Queue *clone() const;
    ~Queue();
    void enqueue(T data);
    T dequeue();
    const T peek() const;
    bool isEmpty() const;
};

#endif