#include <iostream>
using namespace std;

int main(){
    int * arr = new int[3];

    for(int i = 0; i<3; i++){
        arr[i] = i*3;
    }

    for(int i = 0; i<3; i++){
        cout << arr[i] << ' ';
    }

    int * tmp = new int[5];

    for(int i = 0; i<3; i++){
        tmp[i] = arr[i];
    }
    delete [] arr;
    arr = tmp;

    tmp = new int[2];
    tmp[0] = arr[0];
    tmp[1] = arr[1];
    delete [] arr;
    arr = tmp;

    return 0;
}