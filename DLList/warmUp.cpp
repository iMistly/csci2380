#include<iostream>
using namespace std;

#include "../Linked Lists/Node.h"

int main(){
    Node* first = new Node(5);
    Node* second = new Node(7);

    first->next = second;
    second->next = first;

    Node* middle = new Node(4.0);
    first->next = middle;
    middle->next = second; //second->next still equal first
}