#include<iostream>
#include <iomanip>
#include<vector>
using namespace std;

struct track{
    string title{};
    vector<string> artists;
    string album{};
    vector<string> genres;
    int length{}; //In seconds
    bool favorited;

    track(string inTitle, vector<string> inArtists, string inAlbum, int inMinutes, int inSeconds, vector<string> inGenres = {}, bool inFav = false){
        title = inTitle;
        artists = inArtists;
        album = inAlbum;
        genres = inGenres;
        length = inMinutes*60 + inSeconds;
        favorited = inFav;
    }
};

class playlist{
    private:
        string name;
        vector<track> tracks;
        int numTracks{};

        //Prints single track
        void printOne(int index, int num){
            cout << '\n' <<
            "Track " << num << ":\n" <<
            "\tTitle:\t  " << tracks[index].title << '\n' <<
            "\tArtists:  " << tracks[index].artists[0];
            for(int j = 1; j<tracks[index].artists.size(); j++){
                cout << ", " << tracks[index].artists[j];}
            cout << '\n' <<
            "\tAlbum:\t  " << tracks[index].album << '\n';
            if(tracks[index].genres.size()>0){
                cout << "\tGenres:   " << tracks[index].genres[0];
                for(int j = 1; j<tracks[index].genres.size(); j++){
                    cout << ", " << tracks[index].genres[j];}
            }
            cout << '\n' <<
            "\tLength:\t  " << tracks[index].length/60 << ":" << setfill('0') << setw(2) << tracks[index].length%60 << '\n';
            if(tracks[index].favorited)
                cout << "✨ This song is favorited!✨\n";
        }

    public:
        //Playlist constructor
        playlist(string inName="New Playlist"){
            name = inName;
        }

        string getName(){
            return name;
        }

        //Add a track
        void addTrack(track newTrack){
            tracks.push_back(newTrack);
            numTracks++;
        }

        //Add a track at an index, so the first track is index 0
        void addTrackIndex(track newTrack, int index){
            if(index>numTracks)
                cout << "Index out of bounds.\n";
            else{
                tracks.insert(tracks.end()-index, newTrack);
                numTracks++;
            }
        }

        //Remove a track
        void removeLastTrack(){
            if(numTracks>1){
                numTracks--; 
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
                    numTracks--; 
                    return; 
                } 
            } 
            cout << "Could not find song titled \"" << target << "\"\n"; 
        } 
 
        //Print the tracks from the newest to oldest 
        void printTracks(){ 
            int counter = 1;
            cout << "Playlist \"" << name << "\":\n";
            for(int i = tracks.size()-1; i>=0; i--){
                printOne(i, counter++);
            }
            cout << '\n';
        }

        //Prints the tracks based off the inserted genre
        void printTracksByGenre(string genre){
            int counter = 1;
            cout << "Tracks under Playlist \"" << name << "\" under the \"" << genre << "\" genre:\n";
            for(int i = tracks.size()-1; i>=0; i--){
                for(int j = 0; j<tracks[i].genres.size(); j++){
                    if(tracks[i].genres[j] == genre){
                        printOne(i, counter++);
                        break;
                    }
                }
            }
            cout << '\n';
        }

        void searchTracks(){

        }
};

int main(){
    playlist minecraft("Minecraft");
    
    minecraft.addTrack(track ("Mice on Venus", {"C418"}, "Minecraft - Volume Alpha", 4, 41, {"Ambient"}));
    minecraft.addTrack(track ("Aria Math", {"C418"}, "Minecraft - Volume Beta", 5, 10, {"Ambient", "Instrumental"}));
    minecraft.addTrack(track ("Firebugs", {"Lena Raine"}, "Minecraft: The Wild Update", 5, 12, {"Ambient", "Electronic", "Instrumental"}, true));
    minecraft.addTrack(track ("Otherside", {"Lena Raine"}, "Minecraft: Caves & Cliffs", 3, 15));
    minecraft.addTrack(track ("Wet Hands", {"C418"}, "Minecraft - Volume Alpha", 1, 30, {}, 1));
    minecraft.addTrack(track ("5", {"Samuel Åberg"}, "Minecraft: The Wild Update", 2, 58));

    minecraft.printTracks();

    minecraft.removeTrackByName("Aria Math");
    minecraft.removeTrackByName("cat");

    minecraft.addTrackIndex(track ("Cat", {"C418"}, "Minecraft - Volume Alpha", 3, 6, {"Ambient", "Instrumental"}, true), 2);
    minecraft.printTracks();

    minecraft.printTracksByGenre("Ambient");

    return 0;
}