#include <iostream>
using namespace std;

int main(){
    int arr[5]; // Declared on the stack
    int* dynArr = new int[5]; // Declared on the heap

    // Assign array with values: 2 4 6 8 10
    for(int i = 0; i<5; i++){
        dynArr[i] = (i+1)*2;
    }
    
    // I need 2 more spaced in my array.
    int* newDynArr = new int[7];
    for(int i = 0; i<5; i++){
        newDynArr[i] = dynArr[i];
    }
    delete [] dynArr;
    
}