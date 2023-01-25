#include <iostream>
using namespace std;

//Declaring functions
int square(int num);
int sumSquare(int a, int b);
void decreasingSquares(int num);

//Main
int main(){
    int num, num2;
    cout << "Insert a number to square: ";
    cin >> num;
    cout << square(num) << endl;
    cout << "Insert two numbers to square and add together: ";
    cin >> num >> num2;
    cout << sumSquare(num, num2) << endl;
    cout << "Insert a number to square and continuously decrement: ";
    cin >> num;
    decreasingSquares(num);
    system("pause");
    return 0;
}

//Functions
int square(int num){
    return num*num;
}
int sumSquare(int a, int b){
    return square(a) + square(b);
}
void decreasingSquares(int num){
    for(int i = num; i>0; i--){
        string str = i==1?"":", ";
        cout << square(i) << str;
    }
    cout << endl;
}