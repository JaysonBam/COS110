#ifndef ARRAYWRAP_H
#define ARRAYWRAP_H


template <typename T>
class ArrayWrap {
private:
    T* m_array;
    int m_size;
    int maxSize;

public:
    ArrayWrap(int size);
    ~ArrayWrap();
    T& operator[](int index);
    void swap(int index1, int index2);
    void push_back(T item);
    T pop_back();
    void remove(int index);
    void clear();
    void print();
};

#include "ArrayWrap.cpp"

#endif
