#include <vector>
#include <iostream>
#include <fstream>
#include "CIty.h"
#include <algorithm>

int main()
{
	std::vector <int> vec = { 1,2,3 };
	std::vector <int> vec1 = { 2,2,2 };
	std::vector<std::vector<int>> matrix = { {1, 4},{2,5},{ 3, 6} };
	std::vector<int> vect = { 2, 2, 2 };
	try
	{
		int scal_prod = ScalProd(vec, vec1);
		std::cout << "Scalar product is: " << scal_prod << std::endl;
		std::vector<int> result = multByVector(vect, matrix);
		std::cout << "Result vector: ";
		for (int val : result) {
			std::cout << val << " "; 
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what();
	}
	std::cout << "First vector: " << std::endl;
	vector<City> cities_1;
	ifstream fin("city1.txt");
	copy(istream_iterator<City>(fin), istream_iterator<City>(), back_inserter(cities_1));
	auto printF = [](const City& C) {
		cout << "Country: " << C.getCountry() << ". " << "City: " << C.getCity() << ". Number of residents: " << C.getPopulation() << endl; };
	for_each(cities_1.cbegin(), cities_1.cend(), printF);
	cout << endl;
	
	vector<City> cities_2;
	ifstream fin1("city2.txt");
	copy(istream_iterator<City>(fin1), istream_iterator<City>(), back_inserter(cities_2));
	std::cout << "Second vector:" << std::endl;
	for_each(cities_2.cbegin(), cities_2.cend(), printF);
	cout << endl;

	vector<City> cities_3;
	ifstream fin2("city3.txt");
	copy(istream_iterator<City>(fin2), istream_iterator<City>(), back_inserter(cities_3));
	std::cout << "Third vector:" << std::endl;
	for_each(cities_3.cbegin(), cities_3.cend(), printF);
	cout << endl;
	std::cout << "Inserting elements of first vector at the begining of first: \n";
	cities_1.insert(cities_1.begin(), cities_2.begin(), cities_2.end());

	std::cout << "Inserting elements of third vector at the end of first: \n";
	cities_1.insert(cities_1.end(), cities_3.begin(), cities_3.end());
	std::cout << "After insertion:" << std::endl;
	for_each(cities_1.cbegin(), cities_1.cend(), printF);
	cout << endl;

	std::cout << "After sorting(ascending order): \n";
	std::sort(cities_1.begin(), cities_1.end(), [](const City& a, const City& b) {
		return a < b;
		});

	for_each(cities_1.cbegin(), cities_1.cend(), printF);
	cout << endl;
	std::string canada = "Canada";
	std::string australia = "Australia";
	std::string united_states = "United_States";
	std::string india = "India";

	std::vector<City> canada_cities;
	int all_residents = 0;
	for (const auto& city : cities_1) {
		if (city.getCountry() == canada ) {
			canada_cities.push_back(city);
			all_residents += city.getPopulation();
		}
	}
	for_each(canada_cities.cbegin(), canada_cities.cend(), printF);
	cout << endl;
	std::cout << "Total population of " << canada << ": " << all_residents << endl;

	all_residents = 0;
	std::vector<City> australian_cities;
	for (const auto& city : cities_1) {
		if (city.getCountry() == australia) {
			australian_cities.push_back(city);
			all_residents += city.getPopulation();
		}
	}
	for_each(australian_cities.cbegin(), australian_cities.cend(), printF);
	cout << endl;
	std::cout << "Total population of " << australia << ": " << all_residents << endl;


	std::vector<City> united_states_cities;
	all_residents = 0;
	for (const auto& city : cities_1) {
		if (city.getCountry() == united_states) {
			united_states_cities.push_back(city);
			all_residents += city.getPopulation();
		}
	}
	for_each(united_states_cities.cbegin(), united_states_cities.cend(), printF);
	cout << endl;
	std::cout << "Total population of " << united_states << ": " << all_residents << endl;

	std::vector<City> india_cities;
	all_residents = 0;
	for (const auto& city : cities_1) {
		if (city.getCountry() == india) {
			india_cities.push_back(city);
			all_residents += city.getPopulation();
		}
	}
	for_each(india_cities.cbegin(), india_cities.cend(), printF);
	cout << endl;
	std::cout << "Total population of " << india << ": " << all_residents << endl;

	
	return 0;
}
