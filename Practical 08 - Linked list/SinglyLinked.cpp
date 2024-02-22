#ifndef SINGLY_SinglyList_CPP
#define SINGLY_SinglyList_CPP

#include "SinglyLinked.h"
#include <iostream>

template<class T>
SinglyList<T>::SinglyList() : List<T>(){
}

template<class T>
SinglyList<T>::SinglyList(T* arr, int size) : List<T>() {
    if (size <= 0 || arr == NULL) return;

    this->head = new Node<T>(arr[0]);
    Node<T>* current = this->head; 

    for (int i = 1; i < size; i++) {
        Node<T>* newNode = new Node<T>(arr[i]);
        current->next = newNode;
        current = current->next;
    }
}


template<class T>
SinglyList<T>::~SinglyList() {
    Node<T>* nodePtr = this->head;
    while (nodePtr){
        this->head = this->head->next;
        delete nodePtr;
        nodePtr = this->head;
    }
}

template<class T>
Node<T>* SinglyList<T>::insert(T data, int pos) {
    Node<T>* newNode = new Node<T>(data);
    Node<T>* nodePtr = this->head;
    Node<T>* prevNode = NULL;

    if (!nodePtr) {
        // The list is empty, insert at the beginning
        this->head = newNode;
    } else {
        int i = 0;
        while (nodePtr && i < pos) {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
            i++;
        }

        if (!prevNode) {
            // Insert at the beginning of the list
            newNode->next = this->head;
            this->head = newNode;
        } else {
            // Insert at the specified position or at the end of the list
            prevNode->next = newNode;
            newNode->next = nodePtr;
        }
    }

    return newNode;
}

template<class T>
int SinglyList<T>::remove(T data) {
    Node<T>* nodePtr = this-> head;
    Node<T>* prevNode = NULL;
    int result = -1;
    if (this->head){
        int index = 0;
        while(nodePtr && nodePtr->getData() != data){
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
            index++;
        }
        if(nodePtr){
            result = index;
            if (nodePtr == this->head){
                this->head = this->head->next;
                delete nodePtr;
            }
            else{
                prevNode->next = nodePtr-> next;
                delete nodePtr;
            }
        }
    }
    return result;
}

template<class T>
Node<T>* SinglyList<T>::operator[](int index) const {
    if (index < 0)
        index += List<T>::size();
    
    if (index >= List<T>::size() || index < 0)
        return NULL;

    Node<T>* nodePtr = this -> head;
    for (int i = 1; i <= index; i++){
        nodePtr = nodePtr->next;
    }

    return nodePtr;
}

template<class T>
Node<T>* SinglyList<T>::operator()(T* dataPtr) const {
    Node<T>* nodePtr = this->head;
    if (nodePtr){
        while (nodePtr && nodePtr->getData() != *dataPtr)
            nodePtr = nodePtr->next;
    
        if (nodePtr)
            return nodePtr;  
    }
    return NULL;
}

template<class T>
int SinglyList<T>::getIndexFromFront(T data) const {
    int s = List<T>::size();
    for (int i = 0; i < s; i++)
        if ((*this)[i]->getData() == data)
            return i;
    return -1;
}

template<class T>
int SinglyList<T>::getIndexFromRear(T data) const {
    int s = List<T>::size();
    for (int i = (s-1); i >= 0; i--)
        if ((*this)[i]->getData() == data)
            return (s-i-1);
    return -1;
}

template <typename T>
void bubbleSort(T* array, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((ascending && array[j] > array[j + 1]) || (!ascending && array[j] < array[j + 1])) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

template<class T>
List<T>* SinglyList<T>::sort(bool order) const {
    int s = List<T>::size();
    T* arr = new T[s];
    for (int i = 0; i < s; i++)
        arr[i] = (*this)[i]->getData();
    bubbleSort(arr,s,order);
    SinglyList<T>* result = new SinglyList(arr,s);
    delete[] arr;
    return result;
}

template<class T>
Node<T>* SinglyList<T>::findSmallest() const {
    Node<T>* nodePtr = this->head;
    if (nodePtr){
        Node<T>* minNode = (*this)[0];
        int s = List<T>::size();
        for (int i = 1; i < s; i++){
            nodePtr = nodePtr->next;
            if (nodePtr->getData() < minNode->getData())
                minNode = nodePtr;
        }
        return minNode;
    }
    return NULL;
}

template<class T>
Node<T>* SinglyList<T>::findBiggest() const {
    Node<T>* nodePtr = this->head;
    if (nodePtr){
        Node<T>* maxNode = (*this)[0];
        int s = List<T>::size();
        for (int i = 1; i < s; i++){
            nodePtr = nodePtr->next;
            if (nodePtr->getData() > maxNode->getData())
                maxNode = nodePtr;
        }
        return maxNode;
    }
    return NULL;
}

template<class T>
List<T>* SinglyList<T>::clone() const {
    int s = List<T>::size();
    T* arr = new T[s];
    for (int i = 0; i < s; i++)
        arr[i] = (*this)[i]->getData();
    SinglyList<T>* result = new SinglyList(arr,s);
    delete[] arr;
    return result;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const SinglyList<T> *sl)
{
    if (sl->head == NULL)
    {
        os << "NULL";
        return os;
    }
    Node<T> *curr = sl->head;
    while (curr != NULL)
    {
        os << curr;
        curr = curr->next;
    }
    return os;
}

#endif /*SinglyList_CPP*/
