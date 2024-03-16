#include "exam.h"

Exam::Exam()
	:student("Pavlo"), subject("Math analysis"), grade(75), gradeInABCsystem('C')
{
	
}

Exam::Exam(std::string student, std::string subject, short int grade, char gradeInABCsystem)
	:student(student), subject(subject), grade(grade), gradeInABCsystem(gradeInABCsystem)
{
}

Exam::Exam(const Exam& E)
	:student(E.student), subject(E.subject), grade(E.grade), gradeInABCsystem('C')
{
}

Exam::~Exam()
{
}

/*xam Exam::getStudent() const
{
	return student;
}

Exam Exam::getSubject() const
{
	return subject;
}

Exam Exam::getGrade() const
{
	return grade;
}*/

void Exam::setGradeInABC()
{
	if (grade < 51)
		gradeInABCsystem = 'F';
	  if (grade >= 51 && grade < 61)
		gradeInABCsystem = 'E';
	  if (grade >= 61 && grade < 71)
	gradeInABCsystem = 'D';
	if (grade >= 71 && grade < 81)
		gradeInABCsystem = 'C';
	 if (grade >= 81 && grade < 90)
		gradeInABCsystem = 'B';
	 if (grade >= 90 && grade < 100)
		 gradeInABCsystem = 'A';


}

void Exam::increaseGrade(short bonuse)
{
	grade += bonuse;
}

void Exam::printGrades() const
{
	std::cout << "Student: "  << student  << ' ' << "Grade:" << grade << " | " << gradeInABCsystem << std::endl;
}
