#include <iostream>
using namespace std;

void printEven(int start, int end);
int largestValue(int arr[], int len);

int main(){
    int const len = 5;
    int array[len] = {15,7,24,12,17};
    largestValue(array, len);
    return 0;
}

//Write a function that will take in the following:
    //a starting number
    //an ending number
//console output: print every even value between those numbers
//returns: nothing
void printEven(int start, int end){
    if(start>end){
        int tmp = start;
        start = end;
        end = tmp;
    }
    cout << "Printing even numbers from " << start << " to " << end << ".\n";
    for(int i = start; i <= end; i++){
        string str = i==end||i==end-1?"":", ";
        if(i%2==0)
            cout << i << str;
    }
}

//Write a function that will return the largest decimal value of an array
    //input parameters: array of values, length
    //returns: largest value
    //console input: nothing
    //console output: largest value
int largestValue(int arr[], int len){
    int largest = arr[0];
    for(int i = 0; i<len; i++){
        if(arr[i]>largest)
            largest = arr[i];
    }
    if(len > 1)
        cout << "The largest of these " << len << " numbers is: " << largest << endl;
    else if(len == 0)
        cout << "There simply was not a number to be found\n";
    else
        cout << "There was only one number and that number is: " << largest << endl;
    return largest;
}