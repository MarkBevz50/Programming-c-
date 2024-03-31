#pragma once
#include "Transport.h"
class Plane : public Transport {
private:
    double ticket_price;

public:
    Plane();
    Plane(std::string brand, int engine_power, double ticket_price);
    Plane(const Plane& P);
    double getUsageCost() const override;
    void writeTo(std::ostream& out) const override;
    Plane* clone()const override;     //Transport*
    void readFrom(std::istream& in) override;
    void print() const override;
};