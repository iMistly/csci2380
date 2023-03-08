#include <iostream>
using namespace std;

#include "DLList.h"

//Prints the list starting from the head
void printList(DLList list){
    DNode* tmp = list.head;
    while(tmp!=nullptr){
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    cout << '\n';
}

//Removes the node from the list with the target value x
//Does not work at head or tail
void moveNode(DLList list, float x){
    DNode* tmp = list.head;
    tmp = list.head;
    while(tmp!=nullptr){
        if(tmp->data==x){
            break;
        }
        tmp = tmp->next;
    }
    if(tmp==nullptr){
        cout << "Could not find a node with the value " << x << ".\n";
        return;
    }
    cout << "Moving node with the value " << x << ".\n";

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    
    tmp->prev = list.tail;
    tmp->next = list.tail->next;
    list.tail->next = tmp;
    list.tail = tmp;
}

int main(){
    DLList list;
    list.head = new DNode();
    list.tail = list.head;

    for(int i = 1; i<10; i++){
        list.tail->next = new DNode(i*i);
        list.tail->next->prev = list.tail;
        list.tail = list.tail->next;
    }

    printList(list);

    moveNode(list, 36);
    printList(list);

    return 0;
}