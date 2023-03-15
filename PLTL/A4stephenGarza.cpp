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

struct playlist{
    string name;
    vector<track> tracks;
    int numTracks{};

    //Playlist constructor
    playlist(string inName="New Playlist"){
        name = inName;
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
        }
        cout << '\n';
    }

    //Add a track
    void addTrack(string title, vector<string> artists, string album, int minutes, int seconds=0){
        track newTrack(title, artists, album, minutes*60+seconds);
        tracks.push_back(newTrack);
    }

    //Remove a track
    void removeLastTrack(){
        tracks.erase(tracks.end());
    }

    //Remove a track by a searching for a specific name
    void removeTrackByName(string target){
        for(int i = 0; i<tracks.size(); i++){
            if(tracks[i].title == target){
                tracks.erase(tracks.begin()+i);
                cout << "Removed \"" << target << "\"\n";
                return;
            }
        }
        cout << "Could not find song titled \"" << target << "\"\n";
    }
};

int main(){
    playlist minecraft("Minecraft");
    
    minecraft.addTrack("Mice on Venus", {"C418"}, "Minecraft - Volume Alpha", 4, 41);
    minecraft.addTrack("Aria Math", {"C418"}, "Minecraft - Volume Beta", 5, 10);
    minecraft.addTrack("Firebugs", {"Lena Raine"}, "Minecraft: The Wild Update", 5, 12);
    minecraft.addTrack("Otherside", {"Lena Raine"}, "Minecraft: Caves & Cliffs", 3, 15);
    minecraft.addTrack("Wet Hands", {"C418"}, "Minecraft - Volume Alpha", 1, 30);
    minecraft.addTrack("5", {"Samuel Åberg"}, "Minecraft: The Wild Update", 2, 58);

    minecraft.printTracks();

    minecraft.removeTrackByName("Aria Math");
    minecraft.removeTrackByName("cat");

    return 0;
}