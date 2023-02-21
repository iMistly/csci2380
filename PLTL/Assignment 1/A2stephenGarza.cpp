#include <string.h> 
#include <iostream> 
using namespace std; 

// Student Class
class Student{ 
    public: 
        string name; 
        int id;
        int numGrades;
        int * grades;

        Student(int x = 3){
            numGrades = x;
            grades = new int[numGrades];
        }
}; 

// Prototype functions
void inputStudent(Student *inStu); 
void printStudent(Student *inStu);
 
int main(){
    int numStu, numGrades;

    cout << "How many students are there?: ";
    cin >> numStu; 

    Student * roster = new Student[numStu];

    cout << "How many grades are there?: ";
    cin >> numGrades;

    for(int i = 0; i<numStu; i++){
        roster[i] = Student(numGrades);
        cout << "\nFor Student " << i+1 << ":\n";
        inputStudent(&roster[i]);
    }
    
    cout << '\n';

    for(int i = 0; i<numStu; i++){
        printStudent(&roster[i]);
        cout << '\n';
        delete [] roster[i].grades;
    }

    delete [] roster;

    return 0; 
} 

// Function Definitions //
void inputStudent(Student *inStu){
    cout << "Enter a name: ";
    cin >> inStu->name;
    cout << "Enter an ID: ";
    cin >> inStu->id;
    for(int i = 0; i<inStu->numGrades; i++){
        cout << "Enter a grade: ";
        cin >> inStu->grades[i];
    }
} 

void printStudent(Student *inStu){
    cout << "Name: " << inStu->name << '\n';
    cout << "ID: " << inStu->id << '\n';
    for(int i = 0; i<inStu->numGrades; i++){
        cout << "Grade " << i+1 << ": " << inStu->grades[i] << '\n';
    }
}