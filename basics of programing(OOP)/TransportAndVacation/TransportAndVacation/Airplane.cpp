#include "Airplane.h"

Plane::Plane() : Transport("", 0), ticket_price(0) {}

Plane::Plane(std::string brand, int engine_power, double ticket_price)
    : Transport(brand, engine_power), ticket_price(ticket_price) {}

Plane::Plane(const Plane& P)
    : Transport(P.brand, P.engine_power), ticket_price(P.ticket_price) {}

double Plane::getUsageCost() const {
    return ticket_price;
}
void Plane::print() const {
    std::cout << "Plane:" << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Engine Power: " << engine_power << std::endl;
    std::cout << "Ticket Price: " << ticket_price << std::endl;
}

void Plane::writeTo(std::ostream& out) const {
    Transport::writeTo(out);
    out << ticket_price << std::endl;
}

Plane* Plane::clone() const
{
    return new Plane(*this);
}

void Plane::readFrom(std::istream& in) {
    Transport::readFrom(in);
    in >> ticket_price;
}