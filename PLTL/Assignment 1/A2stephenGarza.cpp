#include <string.h> 
#include <iostream> 
using namespace std; 

// Student Class
class Student{ 
    public: 
        string name; 
        int id;
        int * grades;

        Student(int x){
            grades = new int[x];
        }
}; 

// Prototype functions
void inputStudent(Student *stuPtr); 
void printStudent(Student *stuPtr);
 
int main(){
    int numStu;

    cout << "How many students are there?: ";
    cin >> numStu; 

    Student stu(numStu);

    Student * studentPtr = &stu;

    inputStudent(studentPtr);

    printStudent(studentPtr);

    return 0; 
} 

// Function Definitions //
void inputStudent(Student *stuPtr){
    cout << "Enter a name: ";
    cin >> stuPtr->name;
    cout << "Enter an ID: ";
    cin >> stuPtr->id;
    for(int i = 0; i<3; i++){
        cout << "Enter a grade: ";
        cin >> stuPtr->grades[i];
    }
} 

void printStudent(Student *stuPtr){
    cout << "Name: " << stuPtr->name << '\n';
    cout << "ID: " << stuPtr->id << '\n';
    for(int i = 0; i<3; i++){
        cout << "Grade " << i+1 << ": " << stuPtr->grades[i] << '\n';
    }
}