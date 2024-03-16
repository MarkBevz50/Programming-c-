#include "Car.h"
#include "Driver.h"
#include "Taxi.h"
#include <iostream>

//Taxi::Taxi(const std::string& cityName, const Car& car, const Driver& driver)
//    : cityName(cityName), car(car), driver(driver) {}

Taxi::Taxi(const std::string& cityName, const std::string& carBrand, int registrationNumber, const std::string& driverName, int driverAge)
    : Car(carBrand, registrationNumber), Driver(driverName, driverAge), cityName(cityName) {}
//void Taxi::printInfo() const {
//    std::cout << "Taxi in " << cityName << ":" << std::endl;
//    car.printInfo();
//    driver.printInfo();
//}
void Taxi::printInfo() const {
    std::cout << "Taxi in " << cityName << ":" << std::endl;
    Car::printInfo();
    Driver::printInfo();
}