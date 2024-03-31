#pragma once
#include <fstream>
#include "CarTrip.h"
#include "FamilyBeachVacation.h"
#include "ClassesUttilities.h"
Trip** readTripFromFile(const std::string& filename, size_t& size);
void printTrips(Trip** trips, size_t size);
int calculateTotalPrice(Trip** trips, size_t size);
Trip* findMostExpensive(Trip** trips, size_t size, char required_type);
void splitTripsByType(Trip** trips, size_t size, Trip**& carTrips, size_t& carTripsCount, Trip**& planeTrips, size_t& planeTripsCount);
Trip* findMostExpensive(Trip** trips, size_t size);
Trip* findCheapestTrip(Trip** trips, size_t size);