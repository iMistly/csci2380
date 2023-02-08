#include<iostream>
using namespace std;

// int x; //Allocating space into a Stack
// string msg; //Allocating a different space into the stack
// int arr[10]; //Allocating 10 spaces into the stack
//An array is continuous information allocated in the stack.
//You cannot change an array's size as that is the only allocated memory that has been permited into the array.
//If you were to call an index that is outside of the array, then it would excede its allocated stack space and attempt to
    //access information that is outside of the array, but most compilers would prevent that.
//Furthermore, a Heap can be created using the Random Access Memory that may or may not be readily available. 
//A stack is a limited space that a program is allowed to manage and create data in, but a heap is as big as the permited
    //allocated space available in RAM. It is possible to use all available RAM in a heap, but that would essentially
    //ruin the computer.
void addOne(int& myNumber){
    myNumber++;
}

int main(){
    int arr[4]= {5, 10, 15, 20};

    //The address of the start of an array
    cout << arr << endl;

    //Increment address
    cout << arr+1 << "\n\n";

    //Dereference operator (*)
    cout << *arr << endl;
    cout << *arr+1 << endl; // 5 + 1 same as arr[0] + 1
    cout << *(arr+1) << "\n\n"; //10 same as arr[1]
    
    //Declare a pointer to an integer
    int* x = arr;
    cout << *x << endl;
    x++;
    cout << *x << endl;
    cout << *arr << "\n\n";

    //Accessing by pointer and dereference
    *x = 99;
    for(int i=0; i<4; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';

    //Printing the array without using arr
    for(int i=-1; i<3; i++){
        cout << *(x+i) << ' ';
    }
    cout << "\n\n";

    //Reference operator (&)
    int myNumber = 7;

    addOne(myNumber);
    cout << myNumber << '\n';
    cout << "Address of myNumber: " << &myNumber << "\n\n";

    int* ptr = &myNumber;
    myNumber++;
    cout << *ptr << endl;
    (*ptr)++;
    cout << myNumber << endl;
}