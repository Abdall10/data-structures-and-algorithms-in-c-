#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;   
    int size;    

public:
    // Constructor
    Stack();

    // Destructor
    ~Stack();

    // Operations
    void push(int value);       
    void pop(int &value);        
    void stackTop(int &value) const; 
    bool isEmpty() const;
    int stackSize() const;
};

#endif
