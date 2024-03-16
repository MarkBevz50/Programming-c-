#pragma once
#include <iostream>
#include <fstream>
int isNegative(int arr[], int n, int partOfArr);
int* createArr(int arr[], int n);
void printArray(int arr[], int n);
class Auditoriums
{
private:
	int number;
	int width;
	int length;
public:
	Auditoriums();
	Auditoriums(int number, int width, int length);
	Auditoriums(const Auditoriums& T);
	~Auditoriums();
	int calculateArea()const;
	int defineFloar()const;
	int getNumber()const;
	int getWidth()const;
	int getLength()const;
	void setNumber(int new_number);
	void setWidth(int new_width);
	void setLength(int new_length);
	void print();
	friend std::istream& operator >> (std::istream& in, Auditoriums& T);
	friend std::ostream& operator << (std::ostream& out,const Auditoriums& T);
};

Auditoriums* CreateArr(int n);
void printArrr(Auditoriums* arr, int n);
int countAudithoriesOnThirdFloor(Auditoriums* arr, int n);
Auditoriums findLargestAudithory(Auditoriums* arr, int n);