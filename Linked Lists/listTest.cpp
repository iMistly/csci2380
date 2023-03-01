#include<iostream>
using namespace std;

#include "LinkedList.h"

int main(){
    LinkedList theList;

    theList.addNode(5);
    theList.addNode(7.4);
    theList.addNode(-13.6);

    theList.printList();

    theList.removeNode(7.4);
    theList.printList();

    return 0;
}

