#include "classList.h"
#include <iostream>
using namespace std;

List::List() {
    head = cursor = prev = NULL;
}

bool List::ListIsEmpty() { return head == NULL; } // true if the list is empty
bool List::cursorIsEmpty() { return cursor == NULL; } // true if the cursor is empty
void List::toFirst() { cursor = head; } // set the cursor to the first node

// return true if the cursor is at the first node
bool List::atFirst() {
    if (ListIsEmpty())
        return cursorIsEmpty();
    else
        return (cursor == head);
}

// move the cursor to the next node
void List::Advance() {
    prev = cursor;
    cursor = cursor->next;
}

// move the cursor to the last node
void List::toEnd() {
    if (!ListIsEmpty()) {
        toFirst();
        while (cursor->next != NULL)
            Advance();
    }
}

// return true if the cursor is at the last node
bool List::atEnd() {
    if (ListIsEmpty())
        return cursorIsEmpty();
    else
        return (cursor->next == NULL);
}

// return the number of nodes in the list
int List::ListCount() {
    int counter = 0;
    node *p = head;
    while (p != NULL) {
        counter++;
        p = p->next;
    }
    return counter;
}

// update the data of the current node
void List::updateData(int d) { cursor->data = d; }

// update the key of the current node
void List::updateKey(int k) { cursor->key = k; }

// return the data of the current node
int List::RetrieveData() { return cursor->data; }

// return the data of the current node
void List::RetrieveData(int &d) { d = cursor->data; }

// insert a new node
void List::insertFirst(int k, int d) {
    node *p = new node;
    p->key = k;
    p->data = d;
    p->next = head;
    head = p;
    cursor = head;
    prev = NULL;
}

// insert a new node after the current node
void List::insertAfter(int k, int d) {
    node *p = new node;
    p->key = k;
    p->data = d;
    p->next = cursor->next;
    cursor->next = p;
}

// insert a new node before the current node
void List::insertBefore(int k, int d) {
    node *p = new node;
    p->key = k;
    p->data = d;
    p->next = cursor;
    prev->next = p;
    cursor = p;
}

// insert a new node at the end
void List::insertEnd(int k, int d) {
    if (ListIsEmpty())
        insertFirst(k, d);
    else {
        toEnd();
        insertAfter(k, d);
    }
}

// delete the current node
void List::deleteNode() {
    node *p = cursor;
    if (!cursorIsEmpty()) {
        if (atFirst()) {
            cursor = cursor->next;
            head = head->next;
            delete p;
        } else {
            cursor = cursor->next;
            prev->next = cursor;
            delete p;
        }
    }
}

// delete the first node
void List::deleteAtFirst() {
    if (!ListIsEmpty()) {
        toFirst();
        deleteNode();
    }
}

// delete the last node
void List::deleteEnd() {
    if (ListIsEmpty()) {
        cout << "The List is Empty\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = cursor = prev = NULL;
        return;
    }

    toFirst();
    while (cursor->next != NULL) {
        prev = cursor;
        cursor = cursor->next;
    }

    prev->next = NULL;
    delete cursor;
    cursor = prev;
}

// make the list empty by deleting all the nodes
void List::MakeListEmpty() {
    while (!ListIsEmpty()) {
        deleteAtFirst();
    }
}

// search for a node by key
bool List::searchByKey(const int &k) {
    toFirst();
    prev = NULL;
    while (cursor != NULL) {
        if (cursor->key == k)
            return true;
        prev = cursor;
        cursor = cursor->next;
    }
    return false;
}

// traverse the list and print its contents
void List::traverse() {
    toFirst();
    while (!cursorIsEmpty()) {
        cout << cursor->key << " : " << cursor->data << endl;
        Advance();
    }
}

// insert a new node in order of key values 
void List::orderInsert(const int &k, const int &d) {
    toFirst();
    while ((cursor != NULL) && (k > cursor->key))
        Advance();
    if (prev == NULL)
        insertFirst(k, d);
    else
        insertBefore(k, d);
}

// sum the data of all the nodes
int sumList(List &L) {
    int sum = 0;
    if (!L.cursorIsEmpty()) {
        L.toFirst();
        while (!L.cursorIsEmpty()) {
            sum += L.RetrieveData();
            L.Advance();
        }
    }
    return sum;
}

// count the number of zeros
int countZeros(List &L) {
    int count = 0;
    if (!L.cursorIsEmpty()) {
        L.toFirst();
        while (!L.cursorIsEmpty()) {
            if (L.RetrieveData() == 0)
                count++;
            L.Advance();
        }
    }
    return count;
}

int RecursiveList_Size(List &L) {
    if (L.cursorIsEmpty())
        return 0;
    else
        return 1 + RecursiveList_Size(L);
}



