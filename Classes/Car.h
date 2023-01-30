//Define Class
    //Attributes
    //Methods
        //Constructors

//Declare

//Access

//Definition of class Car
class Car{
    private:
        int miles;

    public:
        string color;

        //Methods
        //add a default value to input value x
        void addMiles(int x=10){
            miles += x;
            cout << "Successfully added " << x << " miles.\n";
            cout << "Total miles driven: " << miles << endl;
        }
        //Constructor
        Car(){
            miles = 0;
            cout << "What color is this car?: ";
            cin >> color;
            cout << "Car successfully created.\n";
        }
    
};