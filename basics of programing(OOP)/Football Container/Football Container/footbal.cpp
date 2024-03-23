#include "footbal.h"
#include "club.h"
footballer::footballer()
	: name("Yuriy"), surname("Scherbina"), goals_scored(69), coef_per_goal(1)
{
}
footballer::footballer(std::string name, std::string surname, int goals_scored, double coef_per_goal)
	:name(name), surname(surname), goals_scored(goals_scored), coef_per_goal(coef_per_goal)
{
}
footballer::footballer(const footballer& F)
	:name(F.name), surname(F.surname), goals_scored(F.goals_scored), coef_per_goal(F.coef_per_goal)
{
}
void footballer::readFrom(std::istream& in)
{
	in >> name >> surname >> goals_scored ;
}
void footballer::writeTo(std::ostream& out)const
{
	out << name << " " << surname << " " << goals_scored;
}
int footballer::getGoals()const
{
	return goals_scored;
}
void footballer::setCoef(int coef)
{
	coef_per_goal = coef;
}
int footballer::calculateTotalIncome() const
{
	double income = goals_scored * coef_per_goal;
	return income ;
}
void footballer::print() const
{
	std::cout << "Footballer: " << name << ' ' << surname << ". Goals scored this year:" << goals_scored << ". Salary:" << calculateTotalIncome() << std::endl;
}
std::istream& operator>>(std::istream& in, footballer& h)
{
	h.readFrom(in);
	return(in);
}
std::ostream& operator<<(std::ostream& out, const footballer& h)
{
	h.writeTo(out);
	return out;
}
