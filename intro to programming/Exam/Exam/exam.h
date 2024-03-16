#pragma once
#include <iostream>
class Exam
{
private:
	std::string student;
	std::string subject;
	short int grade;
	char gradeInABCsystem = 'F';
public:
	Exam();
	Exam(std::string student, std::string subject, short int grade, char gradeInABCsystem);
	Exam(const Exam& E);
	~Exam();
	Exam getStudent()const;
	Exam getSubject()const;
	Exam getGrade()const;
	void setGradeInABC();
	void setStudent(std::string newStudent);
	void setSubject(std::string newSubject);
	Exam setGrade(short int grade);
	Exam setGradeInABC(char grade);
	bool operator > (Exam& T);
	void increaseGrade(short bonuse);
	void printGrades()const;
};
std::istream& operator >> (std::istream& in, Exam& E);
std::ostream& operator << (std::ostream& out, const Exam& T);