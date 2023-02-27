///////////////////////////////////////////////////////////////////////
// Please complete this assignment
// PLTL CSCI 2380-01
// Instructor: Erik Enriquez
// PLTL Mentors: Izabella Valero & Carter Vavra
// Name: Stephen Garza
// Date: 2/27/2023
// Assignment 3
//////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stack>
using namespace std;

int main() {
	// initialize your variables
    int amntWords{};
    string word;

	// create a stack of strings
	stack<string> stringStack;

	// ask user: "how many words are in this sentence?"
	// store variable from user
    cout << "How many words are in this sentence?: ";
    cin >> amntWords;

	// create a for loop to enter words into the stack
		// loop should last for number of words user entered
		// loop should ask for a single word each time
		// use .push(userInput) to add the word to the stack
    for(int i = 0; i<amntWords; i++){
        cout << "Enter word " << i+1 << ": ";
        cin >> word;
        stringStack.push(word);
    }

	// print the stack
		// should use a for loop
		// use .isEmpty() to see if stack is empty
		// hint: loop should last as long as the stack is NOT empty
		// use .top() and .pop() to print
    for(; !stringStack.empty(); stringStack.pop()){
        cout << stringStack.top() << ' ';
    }

}