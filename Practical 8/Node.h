#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

template<class T>
class Node;

template<class T>
std::ostream& operator<<(std::ostream&, const Node<T>*);

template<class T>
class Node{
    private:
        T data;
    public:
        Node<T>* next;
        Node(T data);
        T getData() const;
        bool operator==(T other) const;
        friend std::ostream& operator<<<>(std::ostream&, const Node*);

};

template<class T>
inline std::ostream& operator<<(std::ostream& os, const Node<T>* n){
    if(n == NULL){
        os << " {NULL}->N[NULL]"; 
        return os;
    } else {
        os << " {" << n->data << "}->";
        if(n->next == NULL){
            os << "N[NULL]";
        } else {
            os << "N[" << n->next->data << "]";
        }
    }
    return os;
}

#include "Node.cpp"

#endif /*NODE_H*/
