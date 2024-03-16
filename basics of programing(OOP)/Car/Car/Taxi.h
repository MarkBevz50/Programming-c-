#pragma once
#include "Car.h"
#include "Driver.h"

class Taxi : protected Car, Driver
{
private:
    std::string cityName;
    /*Car car;
    Driver driver;*/

public:
    Taxi(const std::string& cityName, const std::string& carBrand, int registrationNumber, const std::string& driverName, int driverAge);
      
   /* Taxi(const std::string& cityName, const, const Driver& driver);*/
    void printInfo() const;
};
