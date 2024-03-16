#include "Driver.h"
#include <iostream>

Driver::Driver(const std::string& name, int age)
    : name(name), age(age) {}

int Driver::getAge() const {
    return age;
}

void Driver::printInfo() const {
    std::cout << "Driver name: " << name << ", Age: " << age << std::endl;
}