#include "function.h"
#include <iostream>
using namespace std;
using std::cin;


int* readArr(int L, int *Array)
{
	for (int i = 0; i < L; ++i)
	{
		cin >> Array[i];
	}
	cout << endl;
	return Array;
}

void printArr(int L,int* Array)
{
	for (int i = 0; i < L; ++i)
	{
		cout << "[ " << Array[i] << "]";
	}
	cout << endl;

}
int* doubled(int L, const int* Array, void(*printArr)(int , int* ))
{
	int* doubledArray = new int[L];
	for (int i = 0; i < L; ++i)
	{
		doubledArray[i] = 2 * Array[i];
	}
	printArr(L, doubledArray);
	return doubledArray;

}
int* squared(int L, const int* Array, void(*printArr)(int , int*))
{
	int* SquaredArray = new int[L];
	for (int i = 0; i < L; ++i)
	{
		SquaredArray[i] = Array[i] * Array[i];
	}
	printArr(L, SquaredArray);
	return SquaredArray;
}
bool isEven(int num)
{
	return num % 2 == 0;
}
bool isPositive(int num)
{
	return num > 0;
}

int* filterArray(const int* Array, int L, int& newSize,bool(*predicate)(int), void(*printArr)(int , int* ))
{
	int count = 0;
	for (int i = 0; i < L; ++i)
	{
		if (predicate(Array[i]))
		{
			++count;
		}
	}
	int* EvenArray = new int[count];
	int index = 0;
	for (int i = 0; i < L; ++i) 
	{
		if (predicate(Array[i])) {
			EvenArray[index++] = Array[i];
		}
	}
	newSize = count;
	printArr(newSize, EvenArray);
	return EvenArray;
}

int* filterArray2(const int* Array, int L, int& newSize, bool(*predicate)(int), void(*printArr)(int, int*))
{
	int count = 0;
	for (int i = 0; i < L; ++i) {
		if (Array[i] > 0) {
			++count;
		}
	}
	int* PositiveArr = new int[count];
	int index = 0;
	for (int i = 0; i < L; ++i) {
		if (Array[i] > 0) {
			PositiveArr[index++] = Array[i];
		}
	}
	newSize = count;
	printArr(newSize, PositiveArr);
	return PositiveArr;
}

const int* GetMin(const int* Array, int L)
{
	const int* MinAddress = Array;
	int min = Array[0];
	for (int i = 0; i < L; ++i)
	{
		if (min >= Array[i]){
			min = Array[i];
		MinAddress = &Array[i];
		}
		++i;
	}
	return MinAddress;
}

int calculateSumInRange(const int* Array, int start, int end)
{
	int sum = 0;
	for (int i = start; i <= end; ++i) {
		sum += Array[i];
	}
	return sum;
}
