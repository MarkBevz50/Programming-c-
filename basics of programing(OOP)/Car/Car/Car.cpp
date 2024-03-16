#include "Car.h"
#include <iostream>

Car::Car(const std::string& brand, int registrationNumber)
    : brand(brand), registrationNumber(registrationNumber) {}

std::string Car::getBrand() const {
    return brand;
}

int Car::getRegistrationNumber() const {
    return registrationNumber;
}

void Car::setRegistrationNumber(int number) {
    registrationNumber = number;
}

void Car::printInfo() const {
    std::cout << "Car brand: " << brand << ", Registration number: " << registrationNumber << std::endl;
}