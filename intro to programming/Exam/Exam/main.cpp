#include "exam.h"

int main()
{
	Exam A("Markiyan Bevz", "Math analysis", 87, '.');
	A.setGradeInABC();
	A.printGrades();
	std::cout << "Enter extra points(in sum it should be <= 100)";
		short int bonuses;
		std::cin >> bonuses;
		std::cout << "Your grade with " << bonuses << "extra points";
		A.increaseGrade(bonuses);
		A.setGradeInABC();
		A.printGrades();

	return 0;
}