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
        for(int i = tracks.size()-1; i>=0; i--){
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
        tracks.erase(tracks.size()-1);
    }
};

int main(){
    playlist minecraft("minecraft");
    
    minecraft.addTrack("Mice on Venus", {"C418"}, "Minecraft - Volume Alpha", 281);
    minecraft.addTrack("Aria Math", {"C418"}, "Minecraft - Volume Beta", 5*60 + 10);

    minecraft.printTracks();

    return 0;
}