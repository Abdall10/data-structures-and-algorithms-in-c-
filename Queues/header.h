#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;


class Queue {
public:
  Queue(int nelements = 128); // Constructor
  Queue (const Queue &); // Copy constructor

  ~Queue(); // Destructor

  void enqueue(int );
  void dequeue(int &);
  void queueFront(int &) const;
  bool isEmpty() const;
  bool isFull() const;
  int queueLength() const;
  int search(int &);

  private:
   int * queue;
   int front;
   int rear;
   int MaxiSize;
};

#endif
