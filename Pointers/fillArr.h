// Define a class FillArr
    // private attributes:
        // An array of size 5 to hold integers
        // An integer to keep track of something

class FillArr{
    private:
        int arr[5];
        int count;

    public:
        FillArr(){
            count = 0;
        }

        void addVal(int x = 0){
            if(count < 5){
                arr[count++] = x;
            }
            else
                cout << "Maximum values inputted. Integer " << x << " was not added.\n";
        }

        void removeVal(){
            if(count > 0 ){
                count--;
                cout << "Removed " << arr[count] << '.';
            }
            else
                cout << "Cannot remove anymore values.";
            cout << '\n';
        }
        
        void printVals(){
            cout << "Your array: ";
            for(int i = 0; i < count; i++){
                cout << arr[i] << ' ';
            }
            cout << '\n';
        }
};