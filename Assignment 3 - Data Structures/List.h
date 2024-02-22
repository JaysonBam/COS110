#ifndef LIST_H
#define LIST_H

/* ------------------------- DO NOT MODIFY THIS FILE ------------------------ */

#include <iostream>
#include <sstream>

template <class T>
class List
{
    public:
    virtual void prepend(T data)=0;
    virtual void append(T data)=0;
    virtual void insert(T data, int index)=0;
    virtual void remove(int index)=0;
    virtual void removeElements(T data)=0;
    virtual void print() const =0;
    virtual void reverse()=0;
    virtual void clear()=0;
    virtual int length() const =0;
    virtual T get(int index) const=0;
    virtual T operator[](int index) const =0;
    virtual void filter(std::string op,T query)=0;
    virtual void swap(int index1, int index2)=0;
    virtual void slice(int start, int end)=0;
    virtual void removeDuplicates()=0;
    List<T>& operator=(const List<T>& other);
};

#endif 