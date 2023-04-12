#include<iostream>
#include<random>
using namespace std;

#include "seqSearch.h"

int main(){
    srand(time(0));
    int length = 50;
    int arr[length];

    for(int i = 0; i<length; i++){
        arr[i] = rand() % 100;
    }
    int target;
    cin >> target;

    cout << (seqSearch(arr, length, target)?"Yes":"Nope") << '\n';

    for(int num : arr){
        cout << num << " ";
    }
    cout << '\n';

    cout << (seqSearchR(arr, length, target)?"Yes":"Nope") << '\n';

    return 0;
}