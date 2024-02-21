#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Tuple.h"
#include "Tuple.cpp"

template<typename T, typename E>
class Dictionary {
private:
    T* keys;
    E* values;
    int currSize;

public:
    Dictionary();
    ~Dictionary();

    void set(T key, E value);
    E at(T key);
    void removeAt(T key);
    void remove(E value);
    bool exists(T key);
    Tuple<int, T*> keysWithValue(E value);
    void swap(T firstKey, T secondKey);
    void clear();
    T* getKeys();
    int size();
};

#endif