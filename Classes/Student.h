//Containers in class

//Class objects in classes

//Define a class, Student, that has the following attributes
    //Name
    //Graduation Date
    //Current Grades (list of decimal values)

class Student{
    public:
        string name;
        short year;
        float grades[5];

        Student(string inName, short inYear=2026){
            name = inName;
            year = inYear;
            for(int i = 0; i<5; i++){
                grades[i] = 0;
            }
        }
        
        void gradeAvg(){
            int sum = 0;
            cout << "Grades: ";
            for(int i = 0; i<5; i++){
                if(i>0)
                    cout << ", ";
                cout << grades[i];
            }
            cout << "\nAverage: " << sum/5.0 << '\n';
        }      
};

class Roster{
    public:
        const int NUM_STUDENTS = 3;
        Student students[3];
        string course;

    Roster(){
        
    }

};