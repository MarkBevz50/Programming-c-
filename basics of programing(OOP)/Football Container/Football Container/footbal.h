#pragma once
#include <iostream>
#include <string>
class footballer
{
public:
	std::string name;
	std::string surname;
	int goals_scored;
	double coef_per_goal;
public:
	footballer();
	footballer(std::string name, std::string surname, int goals_scored, double coef_per_goal);
	footballer(const footballer& F);
	void readFrom(std::istream & in);
	void writeTo(std::ostream& out)const;
	int getGoals()const;
	void setCoef(int coef);
	int calculateTotalIncome()const;
	void print()const;
	};
std::istream& operator>>(std::istream& in, footballer& h);
std::ostream& operator <<(std::ostream& out,const footballer& h);