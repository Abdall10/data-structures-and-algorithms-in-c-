#include "header.h"
#include <iostream>
using namespace std;

int main() {
    Stack s(7);  

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // Print top
    int topValue;
    s.stackTOP(topValue);
    cout << "Top element: " << topValue << endl;

    // Find middle
    int mid;
    s.findMiddle(mid);
    cout << "Middle element: " << mid << endl;

    // Delete middle
    s.deleteMiddle();
    s.findMiddle(mid);
    cout << "Middle element after deletion: " << mid << endl;

    // Pop element
    int popped;
    s.pop(popped);
    cout << "Popped element: " << popped << endl;

    // Stack size
    cout << "Current stack size: " << s.stackSize() << endl;

    // Check if empty/full
    cout << "Is stack empty? " << (s.stackIsEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (s.stackIsFull() ? "Yes" : "No") << endl;

    // Test copy constructor
    Stack s2(s);
    s2.stackTOP(topValue);
    cout << "Top of copied stack: " << topValue << endl;

    return 0;
}
