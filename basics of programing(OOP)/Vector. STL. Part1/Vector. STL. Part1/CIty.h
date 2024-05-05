#pragma once
#include <iostream>
#include <string>
using namespace std;
class City
{
private:
	string city_country;
	string city_name;
	int number_of_population;
public:
	City(string country = "", string name = "", int population = 0)
		:city_country(country), city_name(name), number_of_population(population)
	{

	}
	City(const City& C)
		:city_country(C.city_country), city_name(C.city_name), number_of_population(C.number_of_population)
	{
	}


	bool operator <(const City& C) const { return number_of_population < C.number_of_population; }
	bool operator ==(const City& C) const
	{
		return city_name == C.city_name && city_country == C.city_country&& number_of_population == C.number_of_population;
	}
	string getCountry() const { return city_country; }
	string getCity() const { return city_name; }
	int getPopulation() const { return number_of_population; }
	void readFrom(istream& in) { in >> city_country >> city_name >> number_of_population; }
	void writeTo(ostream& out) const { out << city_name << ", " << city_country << ", " << number_of_population; }
	void setCountry(string Country) { city_country = Country; }
};

istream& operator>>(istream& in, City& C)
{
	C.readFrom(in); return in;
}

ostream& operator<<(ostream& out, const City& C)
{
	C.writeTo(out); return out;
}



//1st part of task
int ScalProd(const std::vector<int> A, const std::vector<int> B)
{
	if (A.size() != B.size())
	{
		throw std::runtime_error("Size of vectors should be equal!");
	}
	int scal_prod = 0;
	/*for (auto it = A.begin(); it != A.end(); ++it)                        // Another version of the scalar product, but using only iterators, is it adequate?
	{
		for (auto it1 = B.begin(); it1 != B.begin() + 1; ++it1)
		{
			scal_prod += *it * *it1;
		}

	}*/
	for (size_t i = 0; i < A.size(); ++i) {
		scal_prod += A[i] * B[i];
	}
	return scal_prod;
};


std::vector<int> multByVector(const std::vector<int> A, const std::vector<std::vector<int>> B) {
	std::vector<int> result(B[0].size(), 0);

	if (A.size() != B.size()) {
		throw std::invalid_argument("Vector A and matrix B have incompatible dimensions for multiplication.");
	}

	for (size_t i = 0; i < B[0].size(); ++i) {
		for (size_t j = 0; j < A.size(); ++j) {
			result[i] += A[j] * B[j][i];
		}
	}

	return result;
}