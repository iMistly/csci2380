#include<iostream>
using namespace std;

class Node{
    public:
        string data;
        Node* left;
        Node* right;

        Node(string inData){
            data = inData;
            left = nullptr;
            right = nullptr;
        }
};

void createTree(Node* root, string arr[], int size){
    Node* current = root;
    for(int i = 1; i<size; i++){
        current = root;
        while(true){
            if(arr[i] < current->data){
                if(current->left == nullptr){
                    current->left = new Node(arr[i]);
                    break;
                }
                else{
                    current = current->left;
                }
            }
            else{
                if(current->right == nullptr){
                    current->right = new Node(arr[i]);
                    break;
                }
                else{
                    current = current->right;
                }
            }
        }
    }
}

bool searchTree(Node* root){
    // Search for user input
    Node* current = root;
    string input;
    cout << "Enter a word to search for: ";
    cin >> input;
    while(current!=nullptr){
        if(input == current->data){
            cout << "Found " << input << " in the tree.\n";
            return true;
        }
        else if(input < current->data){
            current = current->left;
        }
        else{
            current = current->right;
            
        }
    }
    cout << "Could not find " << input << " in the tree.\n";
    return false;
}

int main(){
    string arr[] = {"And", "the", "man", "in", "the", "back", "said,", "Everyone", "attack",
    "And", "it", "turned", "into", "a", "ballroom", "blitz",
    "And", "the", "girl", "in", "the", "corner", "said,", "Boy", "I", "want", "to", "warn", "you",
    "It'll", "turn", "into", "a", "ballroom", "blitz",
    "Ballroom", "blitz,", "ballroom", "blitz,", "ballroom", "blitz,", "ballroom", "blitz",
    "Oh", "reaching", "out", "for", "something",
    "Touching", "nothing's", "all", "I", "ever", "do",
    "Oh", "I", "softly", "call", "you", "over",
    "Then", "you", "appear", "there's", "nothing", "left", "of", "you"};
    Node* root = new Node(arr[0]);
    Node* current = root;
    createTree(root, arr, 60);
    searchTree(root);
    return 0;
}