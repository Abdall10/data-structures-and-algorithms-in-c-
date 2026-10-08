#include "classList.h"
#include <iostream>
#include <string>

// function implementation
List::List() {
    head = cursor = prev = nullptr;
}

 // function ( check if the list is empty )
bool List::ListIsEmpty() {  
   // if(head == nullptr) return true;
   // else return false;
   return(head == nullptr);
}

//function ( check if the cursor is empty )
bool List::cursorIsEmpty() {
    return(cursor == nullptr);
}

// function ( set cursor to value of head )
void List::toFirst() {
    cursor = head;
}

// function ( check if cursor is at head )
bool List::atFirst() {
    if(ListIsEmpty())
    {
     if (cursorIsEmpty())
        return true;
        else 
        return false;
    }
    else return(cursor == head);
}

// function ( move cursor to next node )
void List::Advance() {
    prev = prev->next = cursor;
}

// function ( to move cursor to last node )
void List::toEnd() {
      if(!ListIsEmpty())
      {
        toFirst();
        while (cursor->next != nullptr)
       Advance();
        
      }
}

// function ( check if cursor is at last node )
bool List::atEnd() {
    if(ListIsEmpty())
    {
      if(cursorIsEmpty())
         return true;
       else
         return false;
    } else 
      return (cursor->next == nullptr);
}

// function ( return the number of nodes in the list )
int List::ListCount() {
    int counter=0;
    node *p;
    while (p != nullptr)
    {
        counter++;
        p = p->next;
    }
    return counter;
    
}

// function ( update the data of the current node )
void List::updateData(char d) {
    cursor->data = d;
}

// function ( update the key of the current node )
void List::updateKey(int k) {
    cursor->key = k;
}

char List::RetrieveData(){
    return cursor->data;
}

void List::RetrieveData(char &x){
    x = cursor->data;
}

void List::insertFirst(int k,char d){
    node *p= new node;
    p->key=k;
    p->data=d;

    p->next= head;
    head= p;
    cursor= head;
    prev= nullptr;
}

void List::insertAfter(int k,char d){
    node *p= new node;
    p->key=k;
    p->data=d;

    p->next= cursor->next;
    cursor->next=p;
}

void List::insertBefore(int k,char d){
    node *p= new node;
    p->key=k;
    p->data=d;

    p->next= cursor;
    prev->next= p;
    cursor= p;
    
}

void List::insertEnd(int k,char d){
    if(ListIsEmpty())
    insertFirst(k,d);
     else {
        toEnd();
    insertAfter(k, d);
     }
}

void List::deleteNode(){
   
    node *p;
    p= cursor;
    if(!cursorIsEmpty())
    {
    if(atFirst())
    {
         cursor=cursor->next;
         head=head->next;
         delete p;
    }else{
      cursor=cursor->next;
      prev->next= cursor;
      delete p;
    }
  }
}

void List::deleteAtFirst(){
    if (!ListIsEmpty()){
        toFirst();
        deleteNode();
       // node *p;
      //  p= head;
       // head= head->next;
      //  cursor=head;
       // delete p;
    }
}

void List::deleteEnd(){
     if (ListIsEmpty()) {
        std::cout << "The List is Empty \n";
        return;
    }

   
    if (head->next == nullptr) {
        delete head;
        head = cursor = prev = nullptr;
        return;
    }

    
    toFirst();             
    while (cursor->next != nullptr) {
        prev = cursor;     
        cursor = cursor->next; 
    }

    
    prev->next = nullptr;    
    delete cursor;          
    cursor = prev;          
}


void List::MakeListEmpty(){
    if(!ListIsEmpty()){
         toFirst();
    while (! ListIsEmpty())
    {
        node *p;
        p = cursor;
        cursor= cursor->next;
        delete p;
     }
    }
    /*
      toFirst();
      while(! ListIsEmpty)
        deleteNode
    */
}

bool List::searchByKey(const int &k) {
    toFirst();
    prev = nullptr;
    while (cursor != nullptr) {
        if (cursor->key == k) {
            return true;
        }
        prev = cursor;
        cursor = cursor->next;
    }
    return false;
}

void List::traverse(){
    toFirst();
    while (! cursorIsEmpty)
    {
        std::cout<< cursor->data << " - "<<cursor->key;
        Advance();
    }
    
}

void List::orderInsert(const char &d, const int &k){
    toFirst();
    while ((cursor !=nullptr) && (k > cursor->key))
    {
        Advance();
        if(prev == nullptr) insertFirst(k,d);
         else insertBefore(k, d);
    }
}