#include <string.h> 
#include <iostream> 
using namespace std; 

class Student{ 
    public: 
        string name; 
        int id; 
        int* grades; 
}; 

//Part 1 
// Function prototype for inputting 
void inputStudent(Student* stuPtr, int count); 

// TODO: Function prototype for printing 
void printStudent(Student* stuPtr, int count);
 

// Main function 

int main(){ 
// Part 1 
// instantitating a Student object 
    Student stu; 

// defining a pointer for the Student object 
    Student* studentPtr = &stu; 

// inputtung from the keyboard into the instance 
cout << "How many grades are there?: ";
cin >> studentPtr->grades[0];

inputStudent(&stu, stu.amnt); 

// TODO: print the object
printStudent(studentPtr, stu.amnt);

return 0; 
} 


//TODO: Function defintions// 

// Part 1 

void inputStudent(Student *stuPtr, int count){
    cout << "Enter a name: ";
    cin >> stuPtr->name;
    cout << "Enter an ID: ";
    cin >> stuPtr->id;
    for(int i = 0; i<count; i++){
        cout << "Enter a grade: ";
        cin >> stuPtr->grades[i];
    }
} 

void printStudent(Student* stuPtr, int count){
    cout << "Name: " << stuPtr->name << '\n';
    cout << "ID: " << stuPtr->id << '\n';
    for(int i = 0; i<count; i++){
        cout << "Grade " << i+1 << ": " << stuPtr->grades[i] << '\n';
    }
}