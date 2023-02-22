#include<iostream>
using namespace std;

#include "fillArr.h"

int main(){
    FillArr myArray;

    myArray.addVal(5);
    myArray.addVal(7);
    myArray.addVal(42);
    myArray.addVal(56);
    myArray.addVal(98);
    myArray.addVal(105);
    
    myArray.removeVal();

    myArray.printVals();

    return 0;
}