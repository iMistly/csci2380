#include<iostream>
using namespace std;

int main(){
    int a = 0, b = 1, c = 0, sum = 0;
    for (;c<1000000;) {
        c = a + b;
        a = b;
        b = c;
        if(c&1 && c<1000000){
            cout << c << '\n';
            sum += c;
        }
    }
    cout << sum << '\n';
    return 0;
}