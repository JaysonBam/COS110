#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"
template<class T>
Node<T>::Node(T data) {
    this->data = data;
    next = NULL;
}

template<class T>
T Node<T>::getData() const {
    return data;
}

// Implement the operator== method
template<class T>
bool Node<T>::operator==(T other) const {
    return data == other;
}
#endif /*NODE_CPP*/