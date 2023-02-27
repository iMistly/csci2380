// Linked Lists
    // One item of data
    // Address of the next item
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;

        Node(int inData){
            data = inData;
        }
};

int main(){
    Node* x = new Node(8);
    Node* y = new Node(7);

    x->next = y;

    cout << x->data << '\n';
    cout << x->next->data << '\n';

    Node* z = new Node(3);
    y->next = z; // x->next->next = z;

    cout << x->next->next->data << '\n'; // y->next->data

    x->next = z; // = y->next = x->next->next
    delete y;

    cout << '\n';
    cout << x->data << '\n';
    cout << x->next->data << '\n';

    return 0;
}