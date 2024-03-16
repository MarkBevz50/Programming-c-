#include "FamilyInsurance.h"

FamilyInsurance::FamilyInsurance() : insurance(100), family_surname("Shevchenko"), family_members(3) {}

FamilyInsurance::FamilyInsurance(std ::string family_surname , int family_members, int base_price)
    : insurance(base_price), family_surname(family_surname), family_members(family_members) {}

FamilyInsurance::FamilyInsurance(const FamilyInsurance& i) : insurance(i),family_surname(i.family_surname), family_members(i.family_members) {}

int FamilyInsurance::calcFullPrice() const {
    return getPrice() * family_members;
}

insurance* FamilyInsurance::clone() const {
    return new FamilyInsurance(*this);
}

void FamilyInsurance::printInfo() const {
    std::cout << family_surname<<" family insurance, family members: " << family_members << ". Total price: " << calcFullPrice() << std::endl;
}

void FamilyInsurance::readFrom(std::istream& in) {
    in >> family_surname >> family_members >> base_price;
}

void FamilyInsurance::writeTo(std::ostream& out) const {
    out << family_surname<< family_members << base_price;
}

