#include <iostream>
using namespace std;

#include "DLList.h"

int main(){
    DLList list;

    DNode* newN = new DNode(2.0);
    list.head = newN;
    list.tail = newN;

    list.tail->next = new DNode(3.1);
    list.tail->next->prev = list.tail;
    list.tail = list.tail->next;

    list.tail->next = new DNode(4.2);
    list.tail->next->prev = list.tail;
    list.tail = list.tail->next;

    list.tail->next = new DNode(5.3);
    list.tail->next->prev = list.tail;
    list.tail = list.tail->next;

    list.tail->prev = list.tail->prev->prev;
    delete list.tail->prev->next;
    list.tail->prev->next = list.tail;

    return 0;
}