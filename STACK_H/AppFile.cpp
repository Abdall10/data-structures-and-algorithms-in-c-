#include "stack.h"
#include <iostream>
using namespace std;

// Constructor
Stack::Stack() {
    top = nullptr;
    size = 0;
}

// Destructor
Stack::~Stack() {
    Node* temp;
    while (top != nullptr) {
        temp = top;
        top = top->next;
        delete temp;
    }
    size = 0;
}

// Check if stack is empty
bool Stack::isEmpty() const {
    return (top == nullptr);
}

// Return current size
int Stack::stackSize() const {
    return size;
}

// Push - إضافة عنصر في الأعلى
void Stack::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    size++;
}

// Pop - إزالة أعلى عنصر
void Stack::pop(int &value) {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    Node* temp = top;
    value = top->data;
    top = top->next;
    delete temp;
    size--;
}


void Stack::stackTop(int &value) const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    value = top->data;
}
