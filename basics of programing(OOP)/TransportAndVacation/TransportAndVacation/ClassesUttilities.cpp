#include "ClassesUttilities.h"

Trip** readTripFromFile(const std::string& filename, size_t& size)
{
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Unable to open file: " << filename << std::endl;
            return nullptr;
        }

        file >> size;
        char tripType;
        Trip** arr = new Trip * [size];

        for (size_t i = 0; i < size; ++i) {
            file >> tripType;
            Trip* prototype = nullptr;

            if (tripType == CarTrip::CARTRIP_TYPE) {
                prototype = new CarTrip();
            }
            else if (tripType == FamilyBeachVacation::PLANEVACATION_TYPE) {
                prototype = new FamilyBeachVacation();
            }

            if (prototype) {
                arr[i] = prototype->clone();
                arr[i]->readFrom(file);
                delete prototype;
            }
        }

        return arr;
    }
void printTrips(Trip** trips, size_t size)
{
   
    std::cout << "List of Trips:" << std::endl;
    for (size_t i = 0; i < size; ++i)
    {
        trips[i]->printInfo();
    }
    std::cout << std::endl;
}

int calculateTotalPrice(Trip** trips, size_t size)
{
    int totalCost = 0;
    for (size_t i = 0; i < size; ++i)
    {
        totalCost += trips[i]->calculateCost();
    }
    return totalCost;
}
Trip* findMostExpensive(Trip** trips, size_t size, char requiered_type)
{
    if (size == 0)
    {
        return nullptr;
    }

    Trip* mostExpensive = trips[0]->clone();

    for (size_t i = 1; i < size; ++i)
    {
        if (mostExpensive->calculateCost() < trips[i]->calculateCost())
        {
            mostExpensive = trips[i];
        }
    }

    return mostExpensive->clone();
}
void splitTripsByType(Trip** trips, size_t size, Trip**& carTrips, size_t& carTripsCount, Trip**& planeTrips, size_t& planeTripsCount) {
    carTrips = new Trip * [size];
    carTripsCount = 0;
    planeTrips = new Trip * [size];
    planeTripsCount = 0;

    for (size_t i = 0; i < size; ++i) {
        CarTrip* carTrip = dynamic_cast<CarTrip*>(trips[i]);
        if (carTrip) {
            carTrips[carTripsCount++] = carTrip;
        }
        else {
            FamilyBeachVacation* planeTrip = dynamic_cast<FamilyBeachVacation*>(trips[i]);
            if (planeTrip) {
                planeTrips[planeTripsCount++] = planeTrip;
            }
        }
    }
}

Trip* findMostExpensive(Trip** trips, size_t size)
{
    if (size == 0)
    {
        return nullptr;
    }

    Trip* mostExpensive = trips[0]->clone();

    for (size_t i = 1; i < size; ++i)
    {
        if (mostExpensive->getTransport()->getUsageCost() < trips[i]->getTransport()->getUsageCost())
        {
            mostExpensive = trips[i];
        }
    }

    return mostExpensive->clone();
   
}

Trip* findCheapestTrip(Trip** trips, size_t size)
{
    if (size == 0)
    {
        return nullptr;
    }

    Trip* leastExpensive = trips[0]->clone();

    for (size_t i = 1; i < size; ++i)
    {
        if (leastExpensive->calculateCost() > trips[i]->calculateCost())
        {
            leastExpensive = trips[i];
        }
    }

    return leastExpensive->clone();
}
