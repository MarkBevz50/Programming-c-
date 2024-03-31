#include "FamilyBeachVacation.h"

FamilyBeachVacation::FamilyBeachVacation()
    :  Trip(new Plane(), ""), family_members(0)
{
}

FamilyBeachVacation::FamilyBeachVacation(const FamilyBeachVacation& F)
:Trip(F.transport->clone(), F.destination), family_members(F.family_members)
{
}

FamilyBeachVacation::FamilyBeachVacation(Plane* plane, const std::string& destination, int family_members)
    : Trip(plane, destination), family_members(family_members) {
    
}
double FamilyBeachVacation::calculateCost() const {
    return family_members *( transport->getUsageCost() + vacation_price); // ������� ������� - ������� ����� ��'� * (������� ������ + ������� ���������)
}

FamilyBeachVacation* FamilyBeachVacation::clone()
{
    return new FamilyBeachVacation(*this);
}

void FamilyBeachVacation::writeTo(std::ostream& out) const
{
    Trip::writeTo(out);
    out << family_members;
}

int FamilyBeachVacation::getFamilyMembers() const
{
    return family_members;
}

void FamilyBeachVacation::readFrom(std::istream& in)
{

    Trip::readFrom(in);
    in >> family_members;
    //Trip::readFrom(in); // ��������� ����� �������� ����� ��� ���������� destination
    //delete transport; // ��������� �������� �������� transport, ���� ���� ��� ���� ������������
    //transport = new Plane(); // ���������� ����� ��'��� transport ���� Plane
    //transport->readFrom(in); // ������� ��� ��� transport � ������ ��������
    //in >> family_members; // ������� ��� ��� family_members � ������ ��������
}

void FamilyBeachVacation::printInfo() const
{
    std::cout << "Destination: " << destination << std::endl;
    std::cout << "Total Cost: " << calculateCost() << std::endl;
}

