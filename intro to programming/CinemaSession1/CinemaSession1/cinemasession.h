#pragma once
#include <iostream>

#include <string>
#include <fstream>
struct CinemaSession
{
	int tickets;
	std::string NameOfFilm;
	std::string DayOfWeek;
	CinemaSession();
	CinemaSession(int tickets, std::string DayOfWeek, std::string NameOfFilm);

};

std::ostream& operator << (std::ostream& out, const CinemaSession& A);
std::istream& operator>>(std::istream& in, CinemaSession& A);
void printSession(CinemaSession* A, int n);
CinemaSession* readFromFile(const std::string& fileName);
int soldOnParticularDay(CinemaSession* array, int n, const std::string& day);
std::string MostProfitableDay(CinemaSession* array, int n);
int soldOnParticularMovie(CinemaSession* array, int n, const std::string& movie);
std::string MostProfitableDayForFilm(CinemaSession* array, int n, std::string film);