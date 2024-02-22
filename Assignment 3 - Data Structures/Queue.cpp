#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

template <class T>
Queue<T>::Queue() : head(NULL), tail(NULL) {}

template <class T>
Queue<T>::Queue(const Queue<T> &other) : head(NULL), tail(NULL)  {
  Node<T>* otherCurrent = other.head;
  Node<T>* thisPrev = NULL;

  while (otherCurrent) {
    Node<T>* newNode = new Node<T>(otherCurrent->data);
    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    otherCurrent = otherCurrent->next;
  }
}

template <class T>
Queue<T>* Queue<T>::clone() const {
  return new Queue<T>(*this);
}

template <class T>
Queue<T>::~Queue() {
  while (!isEmpty()) {
    dequeue();
  }
}

template <class T>
void Queue<T>::enqueue(T data) {
  Node<T>* newNode = new Node<T>(data);
  if (!head){
    head = newNode;
    tail = newNode;
  } 
  else{
    tail->next = newNode;
    tail = newNode;
  }
}

template <class T>
T Queue<T>::dequeue() {
  if (isEmpty()) 
    return T();

  T data = head->data;
  Node<T>* temp = head;
  head = head->next;
  delete temp;
  return data;
}

template <class T>
const T Queue<T>::peek() const {
  if (isEmpty()) 
    return T(); 

  return head->data;
}

template <class T>
bool Queue<T>::isEmpty() const {
  return head == NULL;
}

#endif