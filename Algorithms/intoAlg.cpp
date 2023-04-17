#include<iostream>
#include<random>
using namespace std;

#include "seqSearch.h"
#include "binSearch.h"

int main(){
    srand(time(0));
    int length = 40;
    int arr[length];
    int arr2[length];
    int target{};

    for(int i = 0; i<length; i++){
        arr[i] = rand() % 100;
    }
    cout << "Enter a target: ";
    cin >> target;

    cout << "Seq " << (seqSearch(arr, length, target)?"Success":"Fail") << '\n';
    cout << "SeqR " << (seqSearchR(arr, length, target)?"Success":"Fail") << '\n';

    cout << "The randomized array:\n";
    for(int num : arr){
        cout << num << " ";
    }
    cout << '\n';

    arr2[0] = rand() % 10;
    cout << arr2[0] << ' ';
    for(int i = 1; i<length; i++){
        arr2[i] = rand() % 9 + 1;
        arr2[i] += arr2[i-1];
        cout << arr2[i] << ' ';
    }
    cout << "\nEnter a new target: ";
    cin >> target;
    cout << "Binary " <<  (binarySearch(arr2, length, target)?"Success":"Failed") << '\n';
    cout << "BinaryR " << (binarySearchR(arr2, length, target)?"Success":"Failed") << '\n';

    return 0;
}