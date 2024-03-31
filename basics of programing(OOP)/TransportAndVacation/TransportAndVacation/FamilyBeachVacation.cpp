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
    return family_members *( transport->getUsageCost() + vacation_price); // Вартість подорожі - кількість членів сім'ї * (вартість квитка + вартість відпочинку)
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
    //Trip::readFrom(in); // Викликаємо метод базового класу для зчитування destination
    //delete transport; // Видаляємо попереднє значення transport, якщо воно вже було ініціалізовано
    //transport = new Plane(); // Ініціалізуємо новий об'єкт transport типу Plane
    //transport->readFrom(in); // Зчитуємо дані про transport з потоку введення
    //in >> family_members; // Зчитуємо дані про family_members з потоку введення
}

void FamilyBeachVacation::printInfo() const
{
    std::cout << "Destination: " << destination << std::endl;
    std::cout << "Total Cost: " << calculateCost() << std::endl;
}

