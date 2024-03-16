#include "Class utilities.h"
insurance** readInsuranceFromFile(const std::string& filename, size_t &size)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return nullptr;
    }
    file >> size;
    char insuranceType;
    insurance** arr = new insurance * [size];
    for (size_t i = 0; i < size; ++i)
    {
        file >> insuranceType;

        insurance* prototype = nullptr;

        if (insuranceType == FamilyInsurance::FAMILY_TYPE)
        {
            prototype = new FamilyInsurance();
        }
        else if (insuranceType == VehicleInsurance::VEHICLE_TYPE)
        {
            prototype = new VehicleInsurance();
        }

        if (prototype)
        {
            arr[i] = prototype->clone();
            arr[i]->readFrom(file);
            delete prototype;
        }
    }

    file.close();
    return arr;
}
void printInsurances(insurance** insurances, size_t size)
{
    std::cout << "List of Insurances:" << std::endl;
    for (size_t i = 0; i < size; ++i)
    {
        insurances[i]->printInfo();
    }
    std::cout << std::endl;
}

int calculateTotalPrice(insurance** insurances, size_t size)
{
    int totalCost = 0;
    for (size_t i = 0; i < size; ++i)
    {
        totalCost += insurances[i]->calcFullPrice();
    }
    return totalCost;
}
 insurance* findMostExpensive( insurance** insurances, size_t size)
{
    if (size == 0)
    {
        return nullptr;
    }

    insurance* mostExpensive =  insurances[0]->clone();

    for (size_t i = 1; i < size; ++i)
    {
        if (*mostExpensive < *insurances[i])
        {
            mostExpensive = insurances[i];
        }
    }

    return mostExpensive->clone();
}

 insurance* findCheapest( insurance** insurances, size_t size)
{
    if (size == 0)
    {
        return nullptr;
    }

    const insurance* cheapest = insurances[0];

    for (size_t i = 1; i < size; ++i)
    {
        if (*insurances[i] < *cheapest)
        {
            cheapest = insurances[i];
        }
    }

    return cheapest->clone();
}
