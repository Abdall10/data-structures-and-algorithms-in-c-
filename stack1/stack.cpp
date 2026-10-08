#include "header.h"
#include <iostream>
using namespace std;


Stack::Stack(int nelements) {
    maxSize = nelements;
    stack = new int[maxSize];
    top = -1;
    cont = 0;
}


// copy constructor
Stack::Stack(const Stack &original) 
 : maxSize(original.maxSize), top(original.top), cont(original.cont) {
    stack = new int[maxSize];
    for (int i = 0; i < maxSize; i++) stack[i] = original.stack[i];
}

Stack::~Stack(){
    delete [] stack;
}

bool Stack::stackIsEmpty() const { return top < 0; }

bool Stack::stackIsFull() const { return top >= (maxSize - 1);}

void Stack::push(int v){
     if (stackIsFull()) 
        cout << "Stack is full!" << endl;
     else stack[++top] = v;
    
}

void Stack::stackTOP(int &value) const {
    if (stackIsEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        value = stack[top];
    }
}

void Stack::pop(int &value) {
    if (stackIsEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        value = stack[top--];
    }
}


int Stack::stackSize() {
    return top + 1;
}

void Stack::findMiddle(int &value) {
    if (stackIsEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        int midIndex = top / 2;
        value = stack[midIndex];
    }
}

void Stack::deleteMiddle() {
    if (stackIsEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        int midIndex = top / 2;
        for (int i = midIndex; i < top; i++)
            stack[i] = stack[i + 1];
        top--;
    }
}
