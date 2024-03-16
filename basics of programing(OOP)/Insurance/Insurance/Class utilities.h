#pragma once
#include "Insurance.h"
#include "FamilyInsurance.h"
#include "VehicleInsurance.h"
insurance** readInsuranceFromFile(const std::string& filename, size_t& size);
void printInsurances( insurance** insurances, size_t size);
int calculateTotalPrice( insurance** insurances, size_t size);
insurance* findMostExpensive( insurance** insurances, size_t size);
insurance* findCheapest( insurance** insurances, size_t size);