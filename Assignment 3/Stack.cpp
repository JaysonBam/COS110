#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"

template <class T>
Stack<T>::Stack() : top(NULL) {}

// template <class T>
// Stack<T>::Stack(const Stack<T> &other) : top(NULL) {
//   Node<T>* otherCurrent = other.top;
//   Node<T>* thisPrev = NULL;

//   while (otherCurrent) {
//     Node<T>* newNode = new Node<T>(otherCurrent->data);
//     if (!top) {
//       top = newNode;
//     } else {
//       thisPrev->next = newNode;
//     }
//     thisPrev = newNode;
//     otherCurrent = otherCurrent->next;
//   }
// }

template <class T>
Stack<T>::Stack(const Stack<T> &other) : top(NULL) {
  if (&other == this) {
    return;
  }

  Node<T>* pushPtr = other.top;

  Stack<T> temp;

  while (pushPtr) {
    temp.push(pushPtr->data);
    pushPtr = pushPtr->next;
  }

  while (!temp.isEmpty())
    push(temp.pop());
}



template <class T>
Stack<T>::~Stack() {
  while (!isEmpty())
    pop();
}

template <class T>
void Stack<T>::push(T data) {
  Node<T>* newNode = new Node<T>(data,top);
  top = newNode;
}

template <class T>
T Stack<T>::pop() {
  if (isEmpty())
    return T();

  T data = top->data;
  Node<T>* temp = top;
  top = top->next;
  delete temp;
  return data;
}

template <class T>
const T Stack<T>::peek() const {
  if (isEmpty()) {
    return T();
  }
  return top->data;
}

template <class T>
bool Stack<T>::isEmpty() const {
  return top == NULL;
}

#endif



