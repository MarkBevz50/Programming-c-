#pragma once
#include <string>

class Car
{
protected:
    std::string brand;
    int registrationNumber;

public:
    Car(const std::string& brand, int registrationNumber);
    virtual ~Car() {};
    std::string getBrand() const;
    int getRegistrationNumber() const;
    void setRegistrationNumber(int number);
    void printInfo() const;
};