#ifndef SINGLY_SinglyList_H
#define SINGLY_SinglyList_H

#include <iostream>

#include "List.h"

template<class T>
class SinglyList;

template<class T>
std::ostream& operator<<(std::ostream& os, const SinglyList<T>*);

template<class T>
class SinglyList: public List<T>{
    public:
        SinglyList();
        SinglyList(T* arr, int size);
        ~SinglyList();
        Node<T>* insert(T data, int pos);
        int remove(T data);
        Node<T>* operator[](int index) const;
        Node<T>* operator()(T* dataPtr) const;
        int getIndexFromFront(T data) const;
        int getIndexFromRear(T data) const;
        List<T>* sort(bool order) const;
        Node<T>* findSmallest() const;
        Node<T>* findBiggest() const;
        List<T>* clone() const; 
        friend std::ostream& operator<<<>(std::ostream& os, const SinglyList*);
};

#include "SinglyLinked.cpp"

#endif /*SinglyList_H*/