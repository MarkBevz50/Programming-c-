#include "cinemasession.h"

CinemaSession::CinemaSession()
{
	this->DayOfWeek = "N/A";
	this->NameOfFilm = "N/A";
	this->tickets = 0;
}

CinemaSession::CinemaSession(int tickets, std::string DayOfWeek, std::string NameOfFilm)
{
	this->DayOfWeek = DayOfWeek;
	this->tickets = tickets;
	this->NameOfFilm = NameOfFilm;
}



std::ostream& operator<<(std::ostream& out, const CinemaSession& A)
{
	out << A.DayOfWeek << ' ' << A.NameOfFilm << ' ' << A.tickets << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, CinemaSession& A) {
	in >> A.DayOfWeek >> A.NameOfFilm >> A.tickets;
	return in;
}

void printSession(CinemaSession* Arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << Arr[i];

	}
}

CinemaSession* readFromFile(const std::string& fileName) {
	std::ifstream ifile = std::ifstream(fileName);
	int n;
	ifile >> n;
	CinemaSession* array = new CinemaSession[n];
	CinemaSession A;

	for (int i = 0; i < n; ++i)
	{
		ifile >> A;
		array[i] = A;

	}
	ifile.close();

	return array;
}

int soldOnParticularDay(CinemaSession* array, int n, const std::string& day) {
	int sum = 0;
	for (size_t i = 0; i < n; ++i) {
		if (array[i].DayOfWeek == day) {
			sum += array[i].tickets;
		}
	}

	return sum;
}

std::string MostProfitableDay(CinemaSession* array, int n)
{
	std::string MostProfitableDay = array[0].DayOfWeek;

	for (size_t i = 0; i < n; ++i)
	{
		if (array[i].tickets > array[i + 1].tickets)
			MostProfitableDay = array[i].DayOfWeek;
	}
	return MostProfitableDay;
}

int soldOnParticularMovie(CinemaSession* array, int n, const std::string& movie)
{
	int sum = 0;
	for (size_t i = 0; i < n; ++i) {
		if (array[i].NameOfFilm == movie)
		{
			sum += array[i].tickets;
		}
	}

	return sum;
	return 0;
}

std::string MostProfitableDayForFilm(CinemaSession* array, int n, std::string film)
{
	std::string MostProfitableDay = array[0].DayOfWeek;
	for (size_t i = 0; i < n; ++i)
	{
		if (array[i].tickets > array[i + 1].tickets)
		{
			MostProfitableDay = array[i].DayOfWeek;
		}

	}
	return MostProfitableDay;
}