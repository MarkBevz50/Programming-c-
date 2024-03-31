#include "Trip.h"

Trip::~Trip()
{
	delete transport;
}
Trip::Trip()
 : transport(nullptr), destination("") {}
Trip::Trip(Transport* transport, const std::string& destination)
	: transport(transport), destination(destination) {}

void Trip::writeTo(std::ostream& out) const {
    out << destination;
    transport->writeTo(out);
}

void Trip::readFrom(std::istream& in) {
    in >> destination;
    transport->readFrom(in);
}

Transport* Trip::getTransport()
{
    return transport;
}
std::ostream& operator<<(std::ostream& out, const Trip& trip) {
    trip.writeTo(out);
    return out;
}

std::istream& operator>>(std::istream& in, Trip& trip) {
    trip.readFrom(in);
    return in;
}
