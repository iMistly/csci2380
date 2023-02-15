#include<iostream>
using namespace std;

#include "house.h"

void printEvenIndex(int *arrPtr, int len){
    for(int i = 0; i<len; i=i+2){
        cout << *(arrPtr+i) << ' ';
    }
    cout << '\n';
}

int main(){
    int myArr[10] = {1,2,3,4,5,6,7,8,9,10};
    printEvenIndex(myArr, 10);

    bool * boolPtr = new bool;
    *boolPtr = true;

    House myHouse;
    myHouse.garage = *boolPtr;

    delete boolPtr;

    House * housePtr = new House;
    housePtr->garage = true;

    return 0;
}