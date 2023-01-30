#include <iostream>
using namespace std;

#include "Car.h"

int main(){
    //Declar two car objects
    Car myCar, myOtherCar;

    //Access - set the color of myCar to purple
    myCar.color = "Purple";
    myOtherCar.color = "Red";

    //Add 10 miles to myCar
    //myCar.miles += 10; You cannot do this
    myCar.addMiles(10);
    myCar.addMiles(7);
    myCar.addMiles(15);
    myCar.addMiles();

    return 0;
}