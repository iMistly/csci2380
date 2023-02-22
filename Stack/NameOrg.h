class NameOrg{
    private:
        string vowNames[3];
        string othrNames[3];
        int c1, c2; //Counters

        bool testVow(string inName){
            char vowels[5] = {'A', 'E', 'I', 'O', 'U'};
            bool isVow = false;
            for(int i = 0; i<5; i++){
                if(inName[0] == vowels[i]){
                    isVow = true;
                }
            }
            return isVow;
        }
    
    public:
        NameOrg(){
            c1 = 0;
            c2 = 0;
        }

        void addName(string inName){
            bool isVow = testVow(inName);

            if(isVow && c1<3){
                vowNames[c1++] = inName;
                cout << "Stored " << inName <<  " as a name starting with a Vowel.\n";
            }
            else if(!isVow && c2<3){
                othrNames[c2++] = inName;
                cout << "Stored " << inName << " as a name starting with a Non-Vowel.\n";
            }
            else
                cout << "There are too many names stored here.\n";
        }

        void removeName(bool isVow){
            if(isVow)
                c1--;
            else
                c2--;
        }

        void removeSpecificName(string inName){
            bool isVow = testVow(inName);
            int index = 0;

            if(isVow){
                for(int i = 0; i < c1; i++){
                    if(vowNames[i] == inName){
                        index = i;
                    }
                }
                for(int i = index+1; i<c1; i++){
                    vowNames[i-1] = vowNames[i];
                }
            }
            else{
                for(int i = 0; i < c2; i++){
                    if(othrNames[i] == inName){
                        index = i;
                    }
                }
                for(int i = index+1; i<c2; i++){
                    othrNames[i-1] = othrNames[i];
                }
            }
            removeName(isVow);
        }

        void display(){
            cout << "\nList of names:\n";
            cout << "Starting with a Vowel:\n";
            for(int i = 0; i < c1; i++){
                cout << vowNames[i] << '\n';
            }
            cout << "\nStarting with a Non-Vowel:\n";
            for(int i = 0; i < c2; i++){
                cout << othrNames[i] << '\n';
            }
        }
};