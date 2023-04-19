#include<iostream>
using namespace std;

#include "bubbleSort.h"

int main(){
    int length = 40;
    int arr[length] = {0};
    srand(time(0));
    
    for(int i = 0; i<length; i++){
        arr[i] = rand() % 100;
        cout << arr[i] << ' ';
    }
    cout << '\n';
    bubbleSort(arr, length);
    for(int i = 0; i<length; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}