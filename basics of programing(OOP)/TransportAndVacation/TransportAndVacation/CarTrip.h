#pragma once
#include "Trip.h"
class CarTrip : public Trip {
private:
    double distance;
public:
    static const char CARTRIP_TYPE = 'C';
    CarTrip();
    CarTrip(Car* car, const std::string& destination, double distance);
    CarTrip(const CarTrip& C);
    double calculateCost() const override;
    CarTrip* clone() override;
    void printInfo() const override;
    void readFrom(std::istream& in) override;
    void writeTo(std::ostream& out) const override;
};