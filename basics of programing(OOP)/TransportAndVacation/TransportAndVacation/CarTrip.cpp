#include "CarTrip.h"

CarTrip::CarTrip()
    :Trip(new Car(), ""), distance(0)
{
}

CarTrip::CarTrip(Car* car, const std::string& destination, double distance)
    : Trip(car, destination), distance(distance) {}

CarTrip::CarTrip(const CarTrip& C)
    : Trip(C.transport->clone(), C.destination), distance(C.distance)
{
}

double CarTrip::calculateCost() const {
    return transport->getUsageCost() *distance/100.0;
}

CarTrip* CarTrip::clone()
{
    return new CarTrip(*this);
}

void CarTrip::printInfo() const {
    std::cout << "Car Travel to: " << destination << std::endl;
    std::cout << "Transport: " << transport->getBrand() << std::endl;
    std::cout << "Cost of Trip: " << calculateCost() << std::endl;
}

void CarTrip::readFrom(std::istream& in)
{
    Trip::readFrom(in);
    in >> distance;
    //Trip::readFrom(in); // ��������� ����� �������� ����� ��� ���������� destination
    //delete transport; // ��������� �������� �������� transport, ���� ���� ��� ���� ������������
    //transport = new Car(); // ���������� ����� ��'��� transport ���� Car
    //transport->readFrom(in); // ������� ��� ��� transport � ������ ��������
    //in >> distance; // ������� ��� ��� distance � ������ ��������
}

void CarTrip::writeTo(std::ostream& out) const
{
    Trip::writeTo(out);
    out << distance;
}
