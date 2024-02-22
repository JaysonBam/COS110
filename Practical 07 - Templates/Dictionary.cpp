#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP

#include "Dictionary.h"
#include <cstddef>
#include <iostream>

template<typename T, typename E>
Dictionary<T, E>::Dictionary() {
    currSize = 0;
    keys = NULL;
    values = NULL;
}

template<typename T, typename E>
Dictionary<T, E>::~Dictionary() {
    clear(); // Call the clear function to deallocate memory
}

template<typename T, typename E>
void Dictionary<T, E>::set(T key, E value) {
    if (currSize == 0) {
        keys = new T[1];
        values = new E[1];
        keys[0] = key;
        values[0] = value;
        currSize++;
        return;
    }
    for (int i = 0; i < currSize; i++) {
        if (keys[i] == key) {
            values[i] = value;
            return;
        }
    }
    T* tempKeys = new T[currSize + 1];
    E* tempValues = new E[currSize + 1];
    for (int i = 0; i < currSize; i++) {
        tempKeys[i] = keys[i];
        tempValues[i] = values[i];
    }
    tempKeys[currSize] = key;
    tempValues[currSize] = value;
    delete[] keys;
    delete[] values;
    keys = tempKeys;
    values = tempValues;
    currSize++;
}

template<typename T, typename E>
E Dictionary<T, E>::at(T key) {
    for (int i = 0; i < currSize; i++) {
        if (keys[i] == key) {
            return values[i];
        }
    }
    return E();
}

template<typename T, typename E>
void Dictionary<T, E>::removeAt(T key) {
    for (int i = 0; i < currSize; i++) {
        if (keys[i] == key) {
            for (int j = i; j < currSize - 1; j++) {
                keys[j] = keys[j + 1];
                values[j] = values[j + 1];
            }
            currSize--;

            T* tempKeys = new T[currSize];
            E* tempValues = new E[currSize];
            for (int j = 0; j < currSize; j++) {
                tempKeys[j] = keys[j];
                tempValues[j] = values[j];
            }

            delete[] keys;
            delete[] values;
            keys = tempKeys;
            values = tempValues;

            if (currSize == 0) {
                delete[] keys;
                delete[] values;
                keys = NULL;
                values = NULL;
            }

            break;
        }
    }
}

template<typename T, typename E>
void Dictionary<T, E>::remove(E value) {
    int removedCount = 0;
    for (int i = 0; i < currSize; i++) {
        if (values[i] == value) {
            for (int j = i; j < currSize - 1; j++) {
                keys[j] = keys[j + 1];
                values[j] = values[j + 1];
            }
            currSize--;
            i--;
            removedCount++;
        }
    }

    if (removedCount > 0) {
        T* tempKeys = new T[currSize];
        E* tempValues = new E[currSize];
        for (int j = 0; j < currSize; j++) {
            tempKeys[j] = keys[j];
            tempValues[j] = values[j];
        }

        delete[] keys;
        delete[] values;
        keys = tempKeys;
        values = tempValues;

        if (currSize == 0) {
            delete[] keys;
            delete[] values;
            keys = NULL;
            values = NULL;
        }
    }
}

template<typename T, typename E>
bool Dictionary<T, E>::exists(T key) {
    for (int i = 0; i < currSize; i++) {
        if (keys[i] == key) {
            return true;
        }
    }
    return false;
}

template<typename T, typename E>
Tuple<int, T*> Dictionary<T, E>::keysWithValue(E value) {
    int t = 0;
    for (int i = 0; i < currSize; i++) {
        if (values[i] == value) {
            t++;
        }
    }

    T* tempKeys = new T[t];
    int index = 0; // Index to populate tempKeys

    for (int i = 0; i < currSize; i++) {
        if (values[i] == value) {
            tempKeys[index++] = keys[i];
        }
    }

    return Tuple<int, T*>(t, tempKeys);
}

template<typename T, typename E>
void Dictionary<T, E>::swap(T firstKey, T secondKey) {
    int fk, sk;
    for (int i = 0; i < currSize; i++) {
        if (keys[i] == firstKey) fk = i;
        if (keys[i] == secondKey) sk = i;
    }
    T temp = keys[fk];
    keys[fk] = keys[sk];
    keys[sk] = temp;
}

template<typename T, typename E>
void Dictionary<T, E>::clear() {
    if (keys != NULL) {
        delete[] keys;
        keys = NULL;
    }
    if (values != NULL) {
        delete[] values;
        values = NULL;
    }
    currSize = 0;
}

template<typename T, typename E>
T* Dictionary<T, E>::getKeys() {
    return keys;
}

template<typename T, typename E>
int Dictionary<T, E>::size() {
    return currSize;
}

#endif
