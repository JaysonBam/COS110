#include "node.h"
#include <iostream>

node::node(int val) : prev(NULL), next(NULL), data(val) {}

node::~node() {
    prev = NULL;
    next = NULL;
}

void node::destroyList() {
    node* current = head();

    while (current){
        node* temp = current;
        current = current->next;
        delete temp;
    }
}

bool node::contains(int val) {
    node* current = head();

    while (current){
        if (current->data == val)
            return true;
        current = current->next;
    }
    return false;
}

void node::insert(int val) {
    if (contains(val)) return;

    node* newnode = new node(val);
    node* current = head();

    while (current) {
        if (current->data > val) {
            // Insert before the current node
            newnode->next = current;
            newnode->prev = current->prev;
            if (current->prev) 
                current->prev->next = newnode;
            current->prev = newnode;
            return;
        } else if (!current->next) {
            // Insert at the end
            newnode->next = NULL;
            newnode->prev = current;
            current->next = newnode;
            return;
        }
        current = current->next;
    }
}



void node::insert(node* n) {
    if (data == n->data) return;

    // Get the heads of both lists
    node* list1 = head();
    node* list2 = n->head();

    while (list2) {
        int val = list2->data;
        node* newnode = list2;  // Remove the node from list2
        list2 = list2->next;   // Move to the next node in list2

        if (!list1->contains(val)) {
            // Insert the node into list1
            node* current = head();
            while (current) {
                if (current->data > val) {
                    // Insert before the current node
                    newnode->next = current;
                    newnode->prev = current->prev;
                    if (current->prev)
                        current->prev->next = newnode;
                    current->prev = newnode;
                    break;
                } else if (!current->next) {
                    // Insert at the end
                    newnode->next = NULL;
                    newnode->prev = current;
                    current->next = newnode;
                    break;
                }
                current = current->next;
            }
        }
        else
            delete newnode;
    }
}



void node::print() {
    int val = data;

    node* current = head();

    while (current) {
        if (current->data == val)
            std::cout << "[" << current->data << "]";
        else
           std::cout << current->data;

        if (current->next)
            std::cout << "->";  

        current = current->next; 
    }
    std::cout<<std::endl;
}

int node::length() {
    int count = 0;
    node* current = head();
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

node* node::remove(int val) {
    node* current = head();
    while (current) {
        if (current->data == val) {
            if (current->prev)
                current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            
            current->next = NULL;
            current->prev = NULL;
            return current;
        }
        current = current->next;
    }
    return NULL;
}

node* node::head(){
    node* current = this;
    while (current->prev)
        current = current->prev;
    return current;
}

node* node::tail() {
    node* current = this;
    while (current->next) 
        current = current->next;
    return current;
}

    // node* list1 = head();
    //     int size1 = length();
    // node* list2 = n->head(); 
    //     int size2 = n->length();


    // int* arr1 = new int[size1];
    // for (int i = 0; i < size1; i++){
    //     arr1[i] = list1->data;
    //     list1 = list1->next;
    // }

    // int* arr2 = new int[size2];
    // for (int i = 0; i < size2; i++){
    //     arr2[i] = list2->data;
    //     list2 = list2->next;
    // }

    // list1 = head();
    // list2 = n->head();

    // for (int i = 0; i < size2; i++)
    //     list1->insert(arr2[i]);
        
    
    // for (int i = 0; i < size1; i++)
    //     list2->insert(arr1[i]);