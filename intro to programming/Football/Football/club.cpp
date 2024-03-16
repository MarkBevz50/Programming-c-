#include "club.h"
using namespace std;

Club::Club()
	: club_name(""), club_rate(0)
{
}

Club::Club(const string& name, int rate)
	: club_name(name), club_rate(rate)
{
}

Club::Club(const Club& C)
	: club_name(C.club_name), club_rate(C.club_rate)
{
}

Club::~Club()
{
}

string Club::getName() const
{
	return club_name;
}

int Club::getRate() const
{
	return club_rate;
}

void Club::print() const
{
	cout << "Club: " << club_name << endl;
}

void Club::readFrom(std::istream& in)
{
	// Manchester United*250
	getline(in, club_name, '*');
	in >> club_rate;
}

void Club::writeTo(std::ostream& out) const
{
	out << club_name << '*' << club_rate;
}

istream& operator>>(istream& in, Club& C)
{
	C.readFrom(in);
	return in;
}

ostream& operator<<(ostream& out, const Club& C)
{
	C.writeTo(out);
	return out;
}