#include <iostream>
#include "Car.h"
#include "Driver.h"
#include "Taxi.h"

    int main() {
        Car car("Porsh Cayen", 1234);

        Driver driver("Oksana Yaroshko", 25);

     /*   Taxi taxi("Lviv", car, driver);*/
        Taxi taxi("Lviv", "Porsh Cayen", 9999, "Oksana Yaroshko", 25);
        taxi.printInfo();
        return 0;
    }

   