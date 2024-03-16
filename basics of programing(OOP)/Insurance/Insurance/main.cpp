#include <iostream>
#include "Insurance.h"
#include "FamilyInsurance.h"
#include "VehicleInsurance.h"
#include "Class utilities.h"
#include <fstream>
int main()
{
    size_t size;
    insurance** arr = readInsuranceFromFile("Insurances.txt", size);
    printInsurances(arr, size);
    int totalCost = calculateTotalPrice(arr, size);
    std::cout << "Total Cost of Insurances: " << totalCost << std::endl;
     insurance* mostExpensive = findMostExpensive(arr, size);
    if (mostExpensive)
    {
        std::cout << "Most Expensive Insurance: ";
        mostExpensive->printInfo();
    }
    const insurance* cheapest = findCheapest(arr, size);
    if (cheapest)
    {
        std::cout << "Cheapest Insurance: ";
        cheapest->printInfo();
    }
    for (size_t i = 0; i < size; ++i)
    {
        delete arr[i];
    }
    delete[] arr;
    return 0;
}