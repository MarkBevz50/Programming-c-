#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <fstream>
//class Programmer {
//protected:
//    std::string name_surname;
//    std::string position;
//    unsigned hours_per_month;
//
//public:
//    Programmer();
//    Programmer(std::string name, const std::string& cur_position, unsigned hour_worked);
//    Programmer(const Programmer& P);
//    virtual ~Programmer() = default;
//
//    virtual double computeSalary() const;
//    virtual void readFrom(std::istream& in);
//    virtual void writeTo(std::ostream& out) const;
//
//    friend std::istream& operator>>(std::istream& in, Programmer& P);
//    friend std::ostream& operator<<(std::ostream& out, const Programmer& P);
//
//    bool operator<(const Programmer& other) const;
//
//    void increaseHours(unsigned hours);
//    virtual void print();
//};
//
//class Tech_lead : public Programmer {
//private:
//    unsigned team_size;
//
//public:
//    Tech_lead();
//    Tech_lead(std::string name, unsigned hour_worked, unsigned team_size);
//    Tech_lead(const Tech_lead& TL);
//    ~Tech_lead() = default;
//
//    double computeSalary() const override;
//    double getTotalBonusPercentage() const;
//
//    void readFrom(std::istream& in) override;
//    void writeTo(std::ostream& out) const override;
//    void print() override;
//
//    friend std::istream& operator>>(std::istream& in, Tech_lead& TL);
//    friend std::ostream& operator<<(std::ostream& out, const Tech_lead& TL);
//};
//
//


// Abstract base class Programmer



// Abstract base class Programmer
class Programmer {
public:
    std::string name_surname;
    std::string position;
    unsigned hours_per_month;

    Programmer();
    Programmer(std::string name, const std::string& cur_position, unsigned hour_worked);
    Programmer(const Programmer& P);

    virtual ~Programmer() = default;

    virtual double computeSalary() const;
    virtual void readFrom(std::istream& in);
    virtual void writeTo(std::ostream& out) const;

    bool operator<(const Programmer& other) const;
    void increaseHours(unsigned hours);
    virtual void print() const;  // Declare print as virtual

    friend std::istream& operator>>(std::istream& in, Programmer& P);
    friend std::ostream& operator<<(std::ostream& out, const Programmer& P);
};

// Concrete class Tech_lead
class Tech_lead : public Programmer {
public:
    unsigned team_size;

    Tech_lead();
    Tech_lead(std::string name, unsigned hour_worked, unsigned team_size);
    Tech_lead(const Tech_lead& TL);

    double computeSalary() const override;
    double getTotalBonusPercentage() const;

    void readFrom(std::istream& in) override;
    void writeTo(std::ostream& out) const override;

    void print() const override;  // Declare print as override
};

// Template class ProgrammerTraits for specialized behavior
template <typename T>
class ProgrammerTraits;

template <>
class ProgrammerTraits<Programmer> {
public:
    static void printBorder() {
        std::cout<< std::setw(20) << std::left<< "-----PROGRAMMER-----" << std::endl;
    }
};

template <>
class ProgrammerTraits<Tech_lead> {
public:
    static void printBorder() {
        std::cout << std::setw(20)<<std::left << "----------TECH-LEAD----------" << std::endl;
    }
};

// Template function to print Programmer with specialized border
template <typename T>
void printProgrammer(const T& prog) {
    ProgrammerTraits<T>::printBorder();
    prog.writeTo(std::cout);
    std::cout << " Wage: " << prog.computeSalary() << '$' << std::endl;
}

void readProgrammersFromFile(const std::string& filename, std::vector<std::unique_ptr<Programmer>>& container);