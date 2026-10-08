#include "classList.h"
#include <iostream>
using namespace std;

int sumList(List &L);
int countZeros(List &L);

void Spilt(List &m, List &P, List &N){
    int data;
    if(!m.ListIsEmpty()){
        m.toFirst();
        while (!m.cursorIsEmpty())
        {
            m.RetrieveData(data);
        if(data<0)
            N.insertEnd( data, 'N');
        else
            P.insertEnd(data, 'P');
        m.deleteNode();
        }
    }
}

int RecursiveList_Size(List &L);


int main() {
    List L, P, N;

    L.insertFirst(-1, 'a');
    L.insertFirst(2, 'b');
    L.insertFirst(-3, 'c');
    L.insertFirst(4, 'd');
    L.insertFirst(0, 'e');

    //cout << "Sum of data in list = " << sumList(L) << endl;
    //cout << "Number of zeros in list = " << countZeros(L) << endl;


   // Spilt(L, P, N);
   // P.traverse();
  //  N.traverse();

   // cout << "Number of nodes in list = " << L.ListCount();


    return 0;
}

