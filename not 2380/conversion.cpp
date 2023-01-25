#include <iostream>
using namespace std;

char convert(int num);

int main(){
    int dec, base, count = 0;
    string ans = "";
    cout << "Insert a decimal integer: ";
    cin >> dec;
    cout << "What base would you like to convert to?: ";
    cin >> base;
    while(true){
        int i = dec%base;
        if(dec>0){
            ans += to_string(i>=10?convert(i):i);
            count++;
        }
        else
            break;
        dec /= base;
    }
    for(int i = count; i>=0; i--){
        cout << ans[i];
    }
}

char convert(int num){
    return 65+num-10;
}