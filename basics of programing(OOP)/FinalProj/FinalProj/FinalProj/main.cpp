#include <algorithm>
#include <iostream>
#include "Programmer.h"
int main() {
    std::vector<std::unique_ptr<Programmer>> programmers;

    // Reading from files
    readProgrammersFromFile("Programmers.txt", programmers);
    readProgrammersFromFile("TechLeads.txt", programmers);

    // Sort by hours worked
    std::sort(programmers.begin(), programmers.end(), [](const std::unique_ptr<Programmer>& a, const std::unique_ptr<Programmer>& b) {
        return *a < *b;
        });
    std::cout << "\nCompany(sorted by hours):\n";
    // Print sorted programmers
    for (const auto& prog : programmers) {
        prog->print();
    }

    std::cout << "\nAfter doubling hours(sorted by wage):\n";

    // Increase hours and sort by salary
    for (auto& prog : programmers) {
        prog->increaseHours(prog->hours_per_month); // Double the hours
    }

    std::sort(programmers.begin(), programmers.end(), [](const std::unique_ptr<Programmer>& a, const std::unique_ptr<Programmer>& b) {
        return a->computeSalary() < b->computeSalary();
        });

    // Print sorted programmers by salary
    for (const auto& prog : programmers) {
        prog->print();
    }

    // Collect statistics
    std::map<std::string, double> salaryStats;
    for (const auto& prog : programmers) {
        salaryStats[prog->position] += prog->computeSalary();
    }

    std::cout << "\nSalary statistics:\n";
    for (const auto& stat : salaryStats) {
        std::cout << "Position: " << stat.first << ", Total Salary: $" << stat.second << std::endl;
    }

    return 0;
}


