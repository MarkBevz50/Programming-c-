#pragma once
#include "Trip.h"
#include "Airplane.h"
class FamilyBeachVacation : public Trip {
private:
    int family_members;
    static const int vacation_price = 1200;
public:
    static const char PLANEVACATION_TYPE = 'P';
    FamilyBeachVacation();
    FamilyBeachVacation(const FamilyBeachVacation& F);
    FamilyBeachVacation(Plane* airplane, const std::string& destination, int familyMembers);
    virtual double calculateCost() const override;
    FamilyBeachVacation* clone() override; //
    virtual void writeTo(std::ostream& out) const override;
    int getFamilyMembers()const;
    virtual void readFrom(std::istream& in) override;
    virtual void printInfo() const override;
};