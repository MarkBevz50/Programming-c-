#pragma once
#include <string>
#include <iostream>

class Club
{
private:
	std::string club_name;
	int club_rate;

public:
	Club();
	Club(const std::string& name, int rate);
	Club(const Club& C);
	~Club();

	std::string getName() const;
	int getRate() const;

	void print() const;

	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, Club& C);
std::ostream& operator<<(std::ostream& out, const Club& C);