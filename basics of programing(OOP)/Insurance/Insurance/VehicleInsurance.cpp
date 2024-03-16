#include "VehicleInsurance.h"

VehicleInsurance::VehicleInsurance()
    :insurance(53), vehicle_name("Leopard 2"), engine_volume(4)
{
}

VehicleInsurance::VehicleInsurance(std::string vehicle_name,int base_price, double engine_volume)
    : insurance(base_price),vehicle_name(vehicle_name), engine_volume(engine_volume) {}

VehicleInsurance::~VehicleInsurance() {}

int VehicleInsurance::calcFullPrice() const {
    double additionalCost = 0.0;

    if (engine_volume > 2.0) {
        additionalCost += getPrice() * 0.15;
    }

    else if (engine_volume > 3.0) {
        additionalCost += getPrice() * 0.25;
    }

    return static_cast<int>(getPrice() + additionalCost);
}
insurance* VehicleInsurance::clone() const {
    return new VehicleInsurance(*this);
}

void VehicleInsurance::printInfo() const {
    std::cout <<vehicle_name<< " vehicle insurance, Engine volume: " << engine_volume << ". Total price: " << calcFullPrice() << std::endl;
}

void VehicleInsurance::readFrom(std::istream& in) {
    
    in >> vehicle_name >>base_price >> engine_volume;
}

void VehicleInsurance::writeTo(std::ostream& out) const {
   
    out << vehicle_name << base_price<< engine_volume;
}