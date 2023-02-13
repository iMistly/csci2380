#include <iostream>
using namespace std;

int main(){
    // Dynamically create new objects
    int x; // Creating an object in the stack

    // *new* keyword
        // Returns an address to the newly created object
    int * newPtr = new int; // This asterisk make this variable a pointer of an integer

    // What is the value of newPtr, and *newPtr
        //newPtr = the address of a random integer in memory
        //*newPtr = nothing

    // Assigning a value of 19 to the new integer
    *newPtr = 19; // This asterisk is a dereference to obtain the value at the address newPtr
    
    // Assigning newPtr with the address of x
        // Assigning a value of 88 to the value at newPtr
    int * oldPtr = newPtr;
    newPtr = &x;
    *newPtr = 88;

    delete newPtr;
    // Printing the old value of 19
        // You cannot, since you do not know the old address of that integer
        // This is a "Memory Leak" :O
    cout << *oldPtr << '\n';

}