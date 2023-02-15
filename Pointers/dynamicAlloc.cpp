#include<iostream>
using namespace std;

#include "house.h"

void printEvenIndex(int *arr, int len){
    for(int i = 0; i<len; i=i+2){
        cout << *(arr+i) << ' ';
    }
    cout << '\n';
}

int main(){
    int myArr[10] = {1,2,3,4,5,6,7,8,9,10};
    printEvenIndex(myArr, 10);

    return 0;
}