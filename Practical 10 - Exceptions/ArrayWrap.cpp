#ifndef ARRAYWRAP_CPP
#define ARRAYWRAP_CPP
#include "ArrayWrap.h"
#include <iostream>

#include "ListException.h"
#include "IndexException.h"
#include "SizeException.h"
#include "ConstructorException.h"

template <typename T>
ArrayWrap<T>::ArrayWrap(int size) : m_array(NULL), m_size(0), maxSize(size) {
    if (maxSize <= 0)
        throw ConstructorException();
    
    m_array = new T[maxSize];
}

template <typename T>
ArrayWrap<T>::~ArrayWrap() {
    if (m_array != NULL){
        delete[] m_array;
        m_array = NULL;
    }  
}

template <typename T>
T& ArrayWrap<T>::operator[](int index) {
    if (index < 0 || index >= m_size)
        throw IndexException(index,m_size);
    
    return m_array[index];
}

template <typename T>
void ArrayWrap<T>::swap(int index1, int index2) {
    if (index1 < 0 || index1 >= m_size)
        throw IndexException(index1,m_size);

    if (index2 < 0 || index2 >= m_size)
        throw IndexException(index2,m_size);

    if (index1 != index2) {
        T temp = m_array[index1];
        m_array[index1] = m_array[index2];
        m_array[index2] = temp;
    }    
}

template <typename T>
void ArrayWrap<T>::push_back(T item) {
    if (m_size >= maxSize)
        throw SizeException(maxSize);

    m_array[m_size++] = item;
}

template <typename T>
T ArrayWrap<T>::pop_back() {
    if (m_size == 0) 
        throw SizeException(m_size);
    
    return m_array[--m_size];
}

template <typename T>
void ArrayWrap<T>::remove(int index) {
    if (index < 0 || index >= m_size)
        throw IndexException(index,m_size);

    for (int i = index; i < m_size - 1; i++)
        m_array[i] = m_array[i + 1];

    m_size--;
}

template <typename T>
void ArrayWrap<T>::clear() {
    m_size = 0;
}

template <typename T>
void ArrayWrap<T>::print() {
    for (int i = 0; i < m_size; i++) {
        std::cout << m_array[i];
        if (i < m_size - 1) std::cout << ",";
    }
    std::cout << std::endl;
}

#endif
