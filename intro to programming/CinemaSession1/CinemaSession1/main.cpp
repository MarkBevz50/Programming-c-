#include "cinemasession.h"
#include <iostream>

using std::string;
using std::cout;
int main()
{

	CinemaSession* arr = readFromFile("Data.txt");
	std::ifstream in = std::ifstream("Data.txt");
	int n;
	in >> n;
	cout << "\tCINEMA SESSIONS" << '\n';
	printSession(arr, n); cout << "\n";
	cout << "\t GENERAL STATISTIC" << '\n';

	cout << "Tickets sold on Saturday: " << soldOnParticularDay(arr, n, "Saturday") << '\n';
	cout << "Tickets sold on Sunday: " << soldOnParticularDay(arr, n, "Sunday") << '\n';
	cout << "Tickets sold on Monday: " << soldOnParticularDay(arr, n, "Monday") << '\n';
	cout << "Tickets sold on Tuesday: " << soldOnParticularDay(arr, n, "Tuesday") << '\n';
	cout << "Most profitable day: " << MostProfitableDay(arr, n) << '\n';
	cout << "All Barbie tickets: " << soldOnParticularMovie(arr, n, "Barbie") << '\n';
	cout << "All Interstellar tickets: " << soldOnParticularMovie(arr, n, "Interstellar") << '\n';
	cout << "All Openheimer tickets: " << soldOnParticularMovie(arr, n, "Openheimer") << '\n';
	cout << "Most profitable Barbie day: " << MostProfitableDayForFilm(arr, n, "Barbie") << '\n';
	cout << "Most profitable Interstellar day: " << MostProfitableDayForFilm(arr, n, "Interstellar") << '\n';
	cout << "Most profitable Openheimer day: " << MostProfitableDayForFilm(arr, n, "Openheimer") << '\n';
	delete[] arr;
	return 0;
}