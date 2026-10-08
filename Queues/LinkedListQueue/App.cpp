#include "header.h"
#include <iostream>
using namespace std;

// Constructor 
Queue::Queue(int nelements) {
    MaxiSize = nelements;
    queue = new int[MaxiSize];
    front = 0;
    rear = -1;
}

// Copy constructor
Queue::Queue(const Queue &q) {
    MaxiSize = q.MaxiSize;
    front = q.front;
    rear = q.rear;
    queue = new int[MaxiSize];

    for (int i = 0; i < MaxiSize; i++)
        queue[i] = q.queue[i];
}

// Destructor
Queue::~Queue() {
    delete[] queue;
}

// Check if empty
bool Queue::isEmpty() const {
    return (rear < front);
}

// Check if full
bool Queue::isFull() const {
    return (rear == MaxiSize - 1);
}

// Enqueue
void Queue::enqueue(int v) {
    if (isFull()) {
        cout << "Queue is full!" << endl;
    } else {
        queue[++rear] = v;
    }
}

// Dequeue
void Queue::dequeue(int &v) {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
    } else {
        v = queue[front++];
    }
}

// Front element
void Queue::queueFront(int &v) const {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
    } else {
        v = queue[front];
    }
}

// Queue length
int Queue::queueLength() const {
    return (rear - front + 1);
}

// Search
int Queue::search(int &v) {
    for (int i = front; i <= rear; i++) {
        if (queue[i] == v)
            return i;
    }
    return -1;
}