#ifndef CLinkedList_H
#define CLinkedList_H

/* ------------------------- DO NOT MODIFY THIS FILE ------------------------ */

#include <iostream>
#include <sstream>
#include <string>
#include "List.h"
#include "Node.h"

template <class T>
class CLinkedList : public List<T>
{
private:
    Node<T> *head;

public:
    CLinkedList();
    ~CLinkedList();
    void prepend(T data);
    void append(T data);
    void remove(int index);
    void insert(T data, int index);
    void removeElements(T data);
    void print() const;
    void reverse();
    void clear();
    int length() const;
    T get(int index) const;
    T operator[](int index) const;
    void filter(std::string op, T query);
    void swap(int index1, int index2);
    void slice(int start, int end);
    void RRotate(int k);
    void LRotate(int k);
    void removeDuplicates();
    CLinkedList<T> &operator=(const CLinkedList<T> &other);
    bool operator==(const CLinkedList<T> &other) const;
    void operator+=(const CLinkedList<T> &other);
    CLinkedList<T> *operator-(const CLinkedList<T> &other) const;
    void consume(CLinkedList<T> &other);
};

#endif