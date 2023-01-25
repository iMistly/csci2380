#include <iostream>
using namespace std;

int main(){
    cout << "This program adds inputted values.\n\n";
    int sum = 0;
    int tmp;
    while(true){
        cout << "Insert a value(or -1 to stop): ";
        cin >> tmp;
        if(tmp < 0)
            break;
        sum += tmp;
    }
    cout << "Your sum is " << sum << ".\n";
    return 0;
}