#include<iostream>
#include<vector>
using namespace std;

struct track{
    string title{};
    vector<string> artists;
    string album{};
    int length{}; //In seconds

    track(string title, vector<string> artists, string album, int length){

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
        for(int i = 0; i<tracks.size(); i++){
            cout << tracks[i].title << '\n';
        }
    }

    //Add a track
    void addTrack(string title, vector<string> artists, string album, int length){
        track newTrack(title, artists, album, length);
        tracks.push_back(newTrack);
    }

    //Remove a track
    void removeTrack(){
        tracks.pop_back();
    }
};

int main(){
    playlist minecraft("minecraft");
    
    minecraft.addTrack("Mice on Venus", {"C418"}, "Minecraft - Volume Alpha", 281);
    

    return 0;
}