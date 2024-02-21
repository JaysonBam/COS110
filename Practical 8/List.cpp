#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"
#include <iostream>

template<class T>
List<T>::List() : head(NULL) {
}

template<class T>
List<T>::~List() {}

template<class T>
int List<T>::size() const {
    int count = 0;
    Node<T>* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

template<class T>
bool List<T>::contains(T data) const {
    Node<T>* current = head;
    while (current != NULL) {
        if (current->getData() == data)
            return true;
        current = current->next;
    }
    return false;
}


#endif /*LIST_CPP*/