#include<iostream>
#include<vector>
using namespace std;

struct track{
    string title{};
    vector<string> artists;
    string album{};
    int length{}; //In seconds

    track(string inTitle, vector<string> inArtists, string inAlbum, int inLength){
        title = inTitle;
        artists = inArtists;
        album = inAlbum;
        length = inLength;
    }
};

class playlist{
    private:
        string name;
        vector<track> tracks;
        int numTracks{};
        vector<bool> favorited;

    public:
        //Playlist constructor
        playlist(string inName="New Playlist"){
            name = inName;
        }

        string getName(){
            return name;
        }

        //Print the tracks from the newest to oldest
        void printTracks(){
            cout << "Playlist \"" << name << "\":\n";
            for(int i = tracks.size()-1; i>=0; i--){
                cout << '\n' <<
                "Track " << abs(i-static_cast<int>(tracks.size())) << ":\n" <<
                "\tTitle:\t  " << tracks[i].title << '\n' <<
                "\tArtists:  " << tracks[i].artists[0];
                for(int j = 1; j<tracks[i].artists.size(); j++){
                    cout << ", " << tracks[i].artists[j];}
                cout << '\n' <<
                "\tAlbum:\t  " << tracks[i].album << '\n' <<
                "\tLength:\t  " << tracks[i].length/60 << ":" << tracks[i].length%60 << '\n';
                if(favorited[i])
                    cout << "✨ This song is favorited!✨\n";
            }
            cout << '\n';
        }

        //Add a track
        void addTrack(string title, vector<string> artists, string album, int minutes, int seconds=0, bool favorite = false){
            track newTrack(title, artists, album, minutes*60+seconds);
            tracks.push_back(newTrack);
            favorited.push_back(favorite);
            numTracks++;
        }

        //Remove a track
        void removeLastTrack(){
            if(numTracks>1){
                numTracks--;
                favorited[numTracks] = false;
                tracks.erase(tracks.end());
            }
            else
                cout << "Playlist is empty.\n";
        }

        //Remove a track by a searching for a specific name
        void removeTrackByName(string target){
            for(int i = 0; i<tracks.size(); i++){
                if(tracks[i].title == target){
                    tracks.erase(tracks.begin()+i);
                    cout << "Removed \"" << target << "\"\n";
                    favorited[i] = false;
                    numTracks--;
                    return;
                }
            }
            cout << "Could not find song titled \"" << target << "\"\n";
        }
};

class mp3{
    private:
        string name;
        vector<playlist> playlists{};
        int numPlaylists{};

    string mainActions(){
        return 
            "--------------------------\n" 
            "1. Make new playlist\n" 
            "2. Display playlist\n" 
            "3. Edit existing playlist\n" 
            "4. Change the name of this mp3\n" 
            "5. Exit mp3\n"
            "--------------------------\n";
    }

    int chooseAction(int min, int max){
        int action;
        while(true){
                cin >> action;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << mainActions() << "Please enter a valid number: ";
                }
                else if(min <= action && action <= max){
                    break;
                }
                else{
                    cout << mainActions() << "Please enter one of the numbers listed: ";
                }
            }
            return action;
    }
    public:
        mp3(string inName){
            name = inName;
        }

        void start(){
            cout <<
            "Welcome to " << name << "!\n\n";
            menu();
        }

        void menu(){
            int action;
            cout <<
            "What would you like to do?\n" <<
            mainActions() <<
            "Enter the number corresponding to the actions provided: ";

            action = chooseAction(1, 5);

            switch(action){
                case 1:
                    makePlaylist();
                    break;
                case 2:
                    displayPlaylists();
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
            }
        }

        void makePlaylist(){
            string newName;
            int action;
            cout << "What would you like playlist #" << playlists.size()+1 << " to be called?\n";
            while(true){
                cin >> newName;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter a valid name: ";
                }
                else{
                    playlist newPlaylist(newName);
                    playlists.push_back(newPlaylist);
                    cout << "Successfully created " << newName << '\n';
                    numPlaylists++;
                    break;
                }
            }
            cout <<
            "Would you like to:\n"
            "------------------\n"
            "1. Edit this playlist\n"
            "2. Go back to the main menu\n"
            "------------------\n";

            action = chooseAction(1, 2);

            switch(action){
                case 1:
                    editPlaylist(playlists[numPlaylists-1]);
                case 2:
                    menu();
                    break;
            }
            
        }

        void displayPlaylists(){
            int dummy;
            if(numPlaylists>=1){
                for(int i = 0; i<numPlaylists; i++){
                    cout << i+1 << ". ";
                    playlists[i].printTracks();
                }
            }
            else
                cout << "There are no playlists to display.\n";
            
            cout << "Send any key to continue...\n";
            cin >> dummy;
            cin.clear();
            cin.ignore();
            cout << "Back to main menu.\n";
            menu();
        }

        void editPlaylist(playlist& inPlaylist){
            int action;
            // For adding a track //
            string name, artist, album;
            vector<string> artists{};
            int numArt, minutes, seconds;
            bool fav;
            char ans;

            // Begin playlist edit
            cout <<
            "What would you like to do with " << inPlaylist.getName() << "?\n"
            "------------------------------------\n"
            "1. Add track\n"
            "2. Remove last track\n"
            "3. Remove a track by name\n"
            "------------------------------------\n";
            action = chooseAction(1, 3);
            
            switch(action){
                case 1:
                    cout << "What is the name of this song?: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "How many artists contributed to this piece?: ";
                    cin >> numArt;
                    for(int i = 0; i < numArt; i++){
                        cout << "For artist " << i+1 << ": ";
                        cin.ignore();
                        getline(cin, artist);
                        artists.push_back(artist);
                    }
                    cout << "What is the name of this album?: ";
                    cin.ignore();
                    getline(cin, album);
                    cout << "How long is this song? (format mm ss): ";
                    cin >> minutes >> seconds;
                    cout << "Is this one of your favorite songs? (y/n): ";
                    cin >> ans;
                    fav = ans=='y'?1:0;

                    inPlaylist.addTrack(name, artists, album, minutes, seconds, fav);
                    break;

                case 2:
                    inPlaylist.removeLastTrack();
                    break;

                case 3:
                    cout << "What is the name of the song you would like to be deleted?: ";
                    cin >> name;
                    inPlaylist.removeTrackByName(name);
                    break;
            }

        }
};

int main(){
    playlist minecraft("Minecraft");
    
    minecraft.addTrack("Mice on Venus", {"C418"}, "Minecraft - Volume Alpha", 4, 41);
    minecraft.addTrack("Aria Math", {"C418"}, "Minecraft - Volume Beta", 5, 10);
    minecraft.addTrack("Firebugs", {"Lena Raine"}, "Minecraft: The Wild Update", 5, 12);
    minecraft.addTrack("Otherside", {"Lena Raine"}, "Minecraft: Caves & Cliffs", 3, 15);
    minecraft.addTrack("Wet Hands", {"C418"}, "Minecraft - Volume Alpha", 1, 30, 1);
    minecraft.addTrack("5", {"Samuel Åberg"}, "Minecraft: The Wild Update", 2, 58);

    minecraft.printTracks();

    minecraft.removeTrackByName("Aria Math");
    minecraft.removeTrackByName("cat");

    // mp3 newPlayer("MyMP3");
    
    // newPlayer.start();

    return 0;
}