#ifndef CLINKEDLIST_CPP
#define CLINKEDLIST_CPP

#include "CLinkedList.h"
#include <iostream>

template <class T>
CLinkedList<T>::CLinkedList() : head(NULL) {}

template <class T>
CLinkedList<T>::~CLinkedList() {
    if (head == NULL)
        return;
    Node<T>* nodePtr = head;
    Node<T>* temp;

    do{
        temp = nodePtr->next;
        delete nodePtr;
        nodePtr = temp;
    }
    while(nodePtr != head);

    head = NULL;
}

template <class T>
void CLinkedList<T>::prepend(T data) {
    Node<T>* newNode = new Node<T>(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        return;
    }

    Node<T>* tail = head;
    while (tail->next != head)
        tail = tail->next;

    newNode->next = head;
    head = newNode;
    tail->next = newNode;
}

template <class T>
void CLinkedList<T>::append(T data) {
    Node<T>* newNode = new Node<T>(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        return;
    }

    Node<T>* tail = head;
    while (tail->next != head)
        tail = tail->next;

    tail->next = newNode;
    newNode->next = head;
}

template <class T>
void CLinkedList<T>::insert(T data, int index) {
    if (index < 0 || index > length()) return;
    if (index == 0){
        prepend(data);
        return;
    }

    if (index == (length()-1)){
        append(data);
        return;
    }

    Node<T>* nodePtr = head;
    Node<T>* prev = NULL;

    for (int i = 1; i <= index; i++){
        prev = nodePtr;
        nodePtr = nodePtr -> next;
    }

    Node<T>* newNode = new Node<T>(data,nodePtr);
    prev->next = newNode;
}

template <class T>
void CLinkedList<T>::remove(int index) {
    if (index < 0 || index >= length()) return;

    if (index == 0) {
        if (length() == 1) {//delete only node
            delete head;
            head = NULL;
        } else {//delete first node
            Node<T>* temp = head;
            Node<T>* tail = head;
            while (tail->next != head)
                tail = tail->next;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    } else {//delete mid/end node
        Node<T>* prevNode = head;
        for (int i = 1; i < index; i++)
            prevNode = prevNode->next;
        Node<T>* nodeToDelete = prevNode->next;
        prevNode->next = nodeToDelete->next;
        delete nodeToDelete;
    }
}


template <class T>
void CLinkedList<T>::removeElements(T data) {
    for (int i = length()-1; i >= 0; i--)
        if (get(i) == data)
            remove(i);
}



template <class T>
void CLinkedList<T>::print() const {
    if (head){
        for (int i = 0; i < length(); i++){
            std::cout<<get(i);
            if (i != length()-1)
                std::cout<<" -> ";  
        }
        std::cout<<std::endl;  
    }
    else{
        std::cout<<"Empty\n"  ;
    }

    

//Circle check

    // if (head){
    // Node<T>* nodePtr = head;
    //     for (int i = 0; i < length()+2; i++){
    //         std::cout<<nodePtr->data;
    //         if (i != length()+2-1){
    //             std::cout<<"->"; 
    //             nodePtr = nodePtr -> next;
    //         }        
    //     }
    // }
    // std::cout<<std::endl; 
}

template <class T>
void CLinkedList<T>::reverse() {
    if (!head) {
        return; 
    }

    Node<T>* p = head;
    Node<T>* c = head->next;
    Node<T>* n = head->next->next;

    do {
        c->next = p;
        p = c;
        c = n;
        n = n->next;
    } while (p != head);

    head = head->next;
}



template <class T>
void CLinkedList<T>::clear() {
    for (int i = length() -1 ; i >= 0; i--)
        remove(i);
}

template <class T>
int CLinkedList<T>::length() const {
    int result = 0;
    if (head==NULL) return 0;
    Node<T>* nodePtr = head;
    result++;
    while(nodePtr->next!=head){
        result++;
        nodePtr = nodePtr->next;
    }
    return result;
}

template <class T>
T CLinkedList<T>::get(int index) const {
    if (index >= length() || index < 0)
        return T();

    Node<T>* nodePtr = this -> head;
    for (int i = 1; i <= index; i++){
        nodePtr = nodePtr->next;
    }

    return nodePtr->data;
}

template <class T>
T CLinkedList<T>::operator[](int index) const {
  return get(index);
}


template<class T>
bool compare(T left, T right, std::string op){
    if (op == ">") return left > right;
    if (op == "<") return left < right;
    if (op == "==") return left == right;
    if (op == "!=") return left != right;
    if (op == ">=") return left >= right;
    if (op == "<=") return left <= right;
    return false;
}

template <class T>
void CLinkedList<T>::filter(std::string op, T query) {
    if (!(op == ">" || op == "<" || op == "==" || op == "!=" || op == ">=" || op == "<=")) return;

    for (int i = length() -1 ; i >= 0; i--)
        if (!compare(get(i),query,op))
            remove(i);
}

template <class T>
void CLinkedList<T>::swap(int index1, int index2) { 
    if (index1 >= length() || index1 < 0) return;
    if (index2 >= length() || index2 < 0) return;
    if (index1 == index2) return;
    
    Node<T>* A = head;
    Node<T>* B = head;

    for (int i = 1; i <= index1; i++)
        A = A->next;

    for (int i = 1; i <= index2; i++)
        B = B->next;

    T temp  = A->data;
    A->data = B->data;
    B->data = temp;
}


template <class T>
void CLinkedList<T>::slice(int start, int end) {
    if (start >= length() || start < 0) return;
    if (end >= length() || end < 0) return;
    if (start > end) return;

    for (int i = length() - 1; i > end; i--)
        remove(i);

    for (int i = start - 1; i >= 0; i--)
        remove(i);
}

inline int mod(int x, int m)
{
    while(x < 0)
        x+=m;
    return x%m;
}

template <class T>
void CLinkedList<T>::RRotate(int k) {
    if (!head) return;
    for (int i = 0; i < k; i++)
        LRotate(length()-1);  
}

template <class T>
void CLinkedList<T>::LRotate(int k) {
    if (!head) return;
    for (int i = 0; i < k; i++)
        head = head -> next;    
}

template <class T>
void CLinkedList<T>::removeDuplicates() {
    for (int i = 0; i < length(); i++)
        for (int j = length() -1 ; j > i; j--)
            if (get(i)==get(j))
                remove(j);
}

template <class T>
CLinkedList<T>& CLinkedList<T>::operator=(const CLinkedList<T>& other) {
    if (this != &other){
        clear();

        int newSize = other.length();
        for (int i = 0; i < newSize; i++)
            insert(other[i],i);
    }    
    return *this;
}

template <class T>
bool CLinkedList<T>::operator==(const CLinkedList<T>& other) const {
    CLinkedList tempLeft,tempRight;
    bool result = true;
    if (length() != other.length()) result = false;
    for (int i = 0; i < length(); i++){
        tempLeft = *this;
        tempLeft.filter("==", get(i));
        tempRight = other;
        tempRight.filter("==", get(i));
        if (tempLeft.length() != tempRight.length())
            result = false;
    }
    return result;
}

template <class T>
void CLinkedList<T>::operator+=(const CLinkedList<T>& other) {
    if (this == &other) return;
    for (int i = 0; i < other.length(); i++)
        append(other[i]);
}

template <class T>
CLinkedList<T>* CLinkedList<T>::operator-(const CLinkedList<T>& other) const {
    CLinkedList<T>* result = new CLinkedList<T>;
    *result = *this;
    for (int i = 0; i < other.length(); i++) {
        result->removeElements(other[i]);
    }

    return result;
}

template <class T>
void CLinkedList<T>::consume(CLinkedList<T>& other) {
    if (this == &other) return;

    if (other.head == NULL) {
        return;
    }

    if (head == NULL){
        head = other.head;
        other.head = NULL;
        return;
    }


    Node<T>* tail = head;
        while (tail->next != head)
            tail = tail->next;     

    Node<T>* otherTail = other.head;
    while (otherTail->next != other.head)
        otherTail = otherTail->next;

    tail->next = other.head;
    otherTail->next = head;
    other.head = NULL;
}

#endif
