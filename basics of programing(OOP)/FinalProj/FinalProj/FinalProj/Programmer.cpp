#include "Programmer.h"


// Implementations for Programmer
#include "programmer.h"

// Implementations for Programmer
Programmer::Programmer() : name_surname("Markiyan_Bevz"), position("Junior"), hours_per_month(0) {}

Programmer::Programmer(std::string name, const std::string& cur_position, unsigned hour_worked)
    : name_surname(name), position(cur_position), hours_per_month(hour_worked) {}

Programmer::Programmer(const Programmer& P)
    : name_surname(P.name_surname), position(P.position), hours_per_month(P.hours_per_month) {}

double Programmer::computeSalary() const {
    double rate = 0.0;
    if (position == "Junior") rate = 10;
    else if (position == "Middle") rate = 26;
    else if (position == "Senior") rate = 45;
    return hours_per_month * rate;
}

void Programmer::readFrom(std::istream& in) {
    in >> name_surname >> position >> hours_per_month;
}

void Programmer::writeTo(std::ostream& out) const {
    out << "Name: " << name_surname << ". Position as a programmer: " << position << ". Hours worked: " << hours_per_month  << ".|| ";
}

std::istream& operator>>(std::istream& in, Programmer& P) {
    P.readFrom(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Programmer& P) {
    P.writeTo(out);
    return out;
}

bool Programmer::operator<(const Programmer& other) const {
    return hours_per_month < other.hours_per_month;
}

void Programmer::increaseHours(unsigned hours) {
    hours_per_month += hours;
}

void Programmer::print() const {
    printProgrammer(*this);
}

// Implementations for Tech_lead
Tech_lead::Tech_lead() : Programmer(), team_size(0) {}

Tech_lead::Tech_lead(std::string name, unsigned hour_worked, unsigned team_size)
    : Programmer(name, "Senior", hour_worked), team_size(team_size) {}

Tech_lead::Tech_lead(const Tech_lead& TL)
    : Programmer(TL), team_size(TL.team_size) {}

double Tech_lead::computeSalary() const {
   const double tech_lead_rate = 50;
    double base_salary = hours_per_month * tech_lead_rate;
    return base_salary * (1 + getTotalBonusPercentage());
}

double Tech_lead::getTotalBonusPercentage() const {
    return team_size * 0.0001;
}

void Tech_lead::readFrom(std::istream& in) {
    Programmer::readFrom(in);
    in >> team_size;
}

void Tech_lead::writeTo(std::ostream& out) const {
    Programmer::writeTo(out);
    out << "Team size: " << team_size;
}



void Tech_lead::print() const {
    printProgrammer(*this);
}
void readProgrammersFromFile(const std::string& filename, std::vector<std::unique_ptr<Programmer>>& container) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    while (file) {
        std::string type;
        file >> type;
        if (type == "Programmer") {
            auto prog = std::make_unique<Programmer>();
            file >> *prog;
            container.push_back(std::move(prog));
        }
        else if (type == "Tech_lead") {
            auto lead = std::make_unique<Tech_lead>();
            file >> *lead;
            container.push_back(std::move(lead));
        }
    }
}