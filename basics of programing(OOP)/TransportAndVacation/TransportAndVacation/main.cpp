#include "Car.h"
#include "CarTrip.h"
#include "Airplane.h"
#include "FamilyBeachVacation.h"
#include "ClassesUttilities.h"
int main() {
    size_t size;
    Trip** trips = readTripFromFile("Trips.txt", size);
    if (trips == nullptr) {
        std::cerr << "Failed to read trips from file." << std::endl;
        return 1;
    }
    printTrips(trips, size);
    int totalCost = calculateTotalPrice(trips, size);
    std::cout << "Total cost of all trips: " << totalCost << std::endl;
    char mostExpensiveType;
    std::cout << "Enter the type of trip you want to find the most expensive (P/C): ";
    std::cin >> mostExpensiveType;

    Trip* mostExpensive = findMostExpensive(trips, size, mostExpensiveType);
    if (mostExpensive != nullptr) {
        std::cout << "The most expensive trip of type " << mostExpensiveType << " is: \n";
        mostExpensive->printInfo();
        delete mostExpensive;
    }
    else {
        std::cout << "No trips of type " << mostExpensiveType << " found." << std::endl;
    }
    Trip** carTrips;
    size_t carTripsCount;
    Trip** planeTrips;
    size_t planeTripsCount;
    splitTripsByType(trips, size, carTrips, carTripsCount, planeTrips, planeTripsCount);
    std::cout << "\nCar trips: " << std::endl;
    printTrips(carTrips, carTripsCount);
    std::cout << "The most expensive car trip: " << std::endl;
    Trip* MostExpensive = findMostExpensive(carTrips, carTripsCount);
    MostExpensive->getTransport()->print();
    std::cout << std::endl;
    std::cout << "Plane trips: " << std::endl;
    printTrips(planeTrips, planeTripsCount);
    std::cout << "The cheapest plane vacation: " << std::endl;
    FamilyBeachVacation* LeastExpensive = dynamic_cast<FamilyBeachVacation*>(findCheapestTrip(planeTrips, planeTripsCount));
    LeastExpensive->printInfo();
    std::cout << "Number of people in cheapest plane trip: " << LeastExpensive->getFamilyMembers();
    delete[] trips;
    delete[] carTrips;
    delete[] planeTrips;
    return 0;
}