#include <iostream>
#include <string>
#include <header.h>


using namespace std;
int main()
{
    Queue q = Queue();

    while(true){
        /* Produce an item in next produced */
            while(counter == Buffer_SIZE){
                /* do nothing */

                buffer[in] = next_produced;
                 in = ( in +1 )  % Buffer_SIZE;
                 counter++;
            }
    }
    return 0;
}