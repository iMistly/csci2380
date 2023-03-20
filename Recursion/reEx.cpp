#include<iostream>
using namespace std;

void countdown(){
    for(int i = 10; i>=0; i--){
        cout << i << '\n';
    }
    cout << "BLASTOFF!\n";
}

//Recursion
void countdownR(int start = 10){
    // **** BASE CASE ****
    if(start<=0)
        cout << start << "\nBLASTOFF!\n";
    else{
        cout << start-- << '\n';
        countdownR(start); //Function in itself
    }
}

void countUp(int start, int max){
    if(start >= max){
        cout << start << "\nDONE!\n";
    }
    else{
        cout << start++ << '\n';
        countUp(start, max);
    }
}

void hello(int count = 0){
    if(count!=0){
        cout << "Hello!\n";
        hello(--count);
    }
}

int main(){
    countdownR();
    countUp(10, 30);
    hello(5);

    return 0;
}