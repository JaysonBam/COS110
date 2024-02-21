#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"
#include <iostream>

template <class T>
List<T>& List<T>::operator=(const List<T>& other)
{
    if (this != &other){
        clear();

        int newSize = other.length();
        for (int i = 0; i < newSize; i++)
            insert(other[i],i);
    }    
    return *this;
}

#endif
