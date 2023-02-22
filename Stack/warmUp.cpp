#include<iostream>
using namespace std;

#include "NameOrg.h"

int main(){
    NameOrg names;

    names.addName("Jimmy");
    names.addName("Anna");
    names.addName("Bobby");
    names.addName("Ethan");
    names.removeSpecificName("Jimmy");
    names.addName("John");
    names.addName("Anthony");
    names.addName("Mike");
    names.removeSpecificName("Ethan");

    names.display();

    return 0;
}