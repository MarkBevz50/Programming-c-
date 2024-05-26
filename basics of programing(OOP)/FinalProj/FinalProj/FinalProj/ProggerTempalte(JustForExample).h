#pragma once

#include <iostream>
#include <string>

// Abstract base class Programmer
class Programmer {
public:
    std::string position;
    unsigned hours_per_month;

    Programmer(const std::string& pos, unsigned hours)
        : position(pos), hours_per_month(hours) {}

    virtual ~Programmer() = default;

    virtual double computeSalary() const = 0;

    virtual void print() const {
        std::cout << "Position: " << position
            << ", Hours per month: " << hours_per_month;
    }
};

// Concrete class JuniorProgrammer
class JuniorProgrammer : public Programmer {
public:
    JuniorProgrammer(const std::string& pos, unsigned hours)
        : Programmer(pos, hours) {}

    double computeSalary() const override {
        return hours_per_month * 1.1; // Rate for Junior
    }
};

// Concrete class MiddleProgrammer
class MiddleProgrammer : public Programmer {
public:
    MiddleProgrammer(const std::string& pos, unsigned hours)
        : Programmer(pos, hours) {}

    double computeSalary() const override {
        return hours_per_month * 2.0; // Rate for Middle
    }
};

// Concrete class SeniorProgrammer
class SeniorProgrammer : public Programmer {
public:
    SeniorProgrammer(const std::string& pos, unsigned hours)
        : Programmer(pos, hours) {}

    double computeSalary() const override {
        return hours_per_month * 2.5; // Rate for Senior
    }
};

class Tech_lead : public SeniorProgrammer {
public:
    unsigned team_size;

    Tech_lead(const std::string& pos, unsigned hours, unsigned teamSize)
        : SeniorProgrammer(pos, hours), team_size(teamSize) {}

    double computeSalary() const override {
        double base_salary = SeniorProgrammer::computeSalary();
        return base_salary * (1 + team_size * 0.0001);
    }

    void print() const override {
        SeniorProgrammer::print();
        std::cout << ", Team size: " << team_size;
    }
};

template<typename T>
class ProgrammerTraits;

template<>
class ProgrammerTraits<JuniorProgrammer> {
public:
    static constexpr double rate = 1.7;
    static void printBorder() {
        std::cout << "============== Junior Programmer ==============\n";
    }
};

template<>
class ProgrammerTraits<MiddleProgrammer> {
public:
    static constexpr double rate = 3;
    static void printBorder() {
        std::cout << "============== Middle Programmer ==============\n";
    }
};

template<>
class ProgrammerTraits<SeniorProgrammer> {
public:
    static constexpr double rate = 4.5;
    static void printBorder() {
        std::cout << "============== Senior Programmer ==============\n";
    }
};

template<>
class ProgrammerTraits<Tech_lead> {
public:
    static constexpr double rate = 3; // Same base rate as Senior, additional logic in class
    static void printBorder() {
        std::cout << "============== Tech Lead ==============\n";
    }
};

template<typename T>
class ProgrammerWrapper {
    T programmer;
public:
    ProgrammerWrapper(const T& prog) : programmer(prog) {}

    void print() const {
        ProgrammerTraits<T>::printBorder();
        programmer.print();
        std::cout << "\n";
    }

    double computeSalary() const {
        return programmer.hours_per_month * ProgrammerTraits<T>::rate;
    }
};
//int main() {
//    JuniorProgrammer junior("Junior", 1200);
//    MiddleProgrammer middle("Middle", 300);
//    SeniorProgrammer senior("Senior", 2);
//    Tech_lead lead("Senior", 160, 5);
//
//    ProgrammerWrapper<JuniorProgrammer> juniorWrapper(junior);
//    ProgrammerWrapper<MiddleProgrammer> middleWrapper(middle);
//    ProgrammerWrapper<SeniorProgrammer> seniorWrapper(senior);
//    ProgrammerWrapper<Tech_lead> leadWrapper(lead);
//
//    juniorWrapper.print();
//    std::cout << "Salary: $" << juniorWrapper.computeSalary() << "\n\n";
//
//    middleWrapper.print();
//    std::cout << "Salary: $" << middleWrapper.computeSalary() << "\n\n";
//
//    seniorWrapper.print();
//    std::cout << "Salary: $" << seniorWrapper.computeSalary() << "\n\n";
//
//    leadWrapper.print();
//    std::cout << "Salary: $" << leadWrapper.computeSalary() << "\n";
//
//    return 0;
//}

