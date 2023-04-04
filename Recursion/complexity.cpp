// The worst case in a search algorithm is called big O notation O(n)
// If n = 10000, then the worst case would have to search through 10000 numbers

// O(n) is a function, that depends on the solution
    // as n increases, the cost increased linearly

// List of numbers {1, 6, 2}
// Display all the products of these numbers
    //1*1, 1*6, 1*2
    //6*1, 6*6, 6*2
    //2*1, 2*6, 2*2
// Nested loop
// The cost grows exponentially O(n^2)
// A better solution w/o repeating values
    //1*1, 1*6, 1*2
    //     6*6, 6*2
    //          2*2
// O(n^2/2)
#include<iostream>
using namespace std;

int main(){
    int nums[10]{}; // Pretend array is full

    // Check if the first and last numbers are equal
    if(nums[0] == nums[sizeof(nums-1)]){
        cout << "Yes\n";
    }


    return 0;
}

// Overall
    // access arr[0]
    // access arr[length-1]
    // check arr[0] and arr[length-1] to compare if equal
    // return based on result

// Solution takes 4 steps, n = 10
// Solution takes 4 steps, n = 100
// Solution takes 4 steps, n = 1000
// Solution takes 4 steps, n = 10000 etc.
// O(4) - constant

// If the numbers are sorted, check if a number is in a list
// {1, 4, 10, 19, 21, 22, 50, 60, 65}
    // Check if 61 is in the list
    // Do not check 1 by 1 in sequence
        // Instead, use some value in the middle
        // Determine if you need to look on the right, or on the left
        