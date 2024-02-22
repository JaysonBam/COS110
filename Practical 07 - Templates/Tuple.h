#ifndef TUPLE_H
#define TUPLE_H

template<typename T, typename E>
class Tuple {
private:
    T firstValue;
    E secondValue;

public:
    Tuple(T, E);
    ~Tuple();

    T getFirst();
    E getSecond();

    bool operator==(Tuple<T, E> t);
};

#endif