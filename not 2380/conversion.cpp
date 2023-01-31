#include <iostream>
using namespace std;

char convert(int num);

int main(){
    int dec, base, count = 0;
    int ans[10];
    cout << "Insert a decimal integer: ";
    cin >> dec;
    cout << "What base would you like to convert to?: ";
    cin >> base;
    for(int j = 0; j<10; j++){
        int i = dec%base;
        if(dec>0){
            ans[j] = i;
            count++;
        }
        else
            j=10;
        dec /= base;
    }
    for(int i = count-1; i>=0; i--){
        if(ans[i]>=10)
            cout << convert(ans[i]);
        else
            cout << ans[i];
    }
    system("pause");
}

char convert(int num){
    return 65+num-10;
}