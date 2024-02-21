#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "Node.h"

template<class T>
class List;

template<class T>
std::ostream& operator<<(std::ostream& os, const List<T>*){return os;};

template<class T>
class List{
    protected:
        Node<T>* head;
    public:
        List();
        virtual ~List();
        virtual Node<T>* insert(T data, int pos) = 0;
        virtual int remove(T data) = 0;
        virtual Node<T>* operator[](int index) const = 0;
        virtual Node<T>* operator()(T* dataPtr) const = 0;
        virtual int getIndexFromFront(T data) const = 0;
        virtual int getIndexFromRear(T data) const = 0;
        virtual List<T>* sort(bool order) const = 0;
        virtual Node<T>* findSmallest() const = 0;
        virtual Node<T>* findBiggest() const = 0;
        virtual List<T>* clone() const = 0;
        virtual int size() const;
        virtual bool contains(T data) const;
        friend std::ostream& operator<<<>(std::ostream& os, const List*);
};

#include "List.cpp"

#endif /*LIST_H*/