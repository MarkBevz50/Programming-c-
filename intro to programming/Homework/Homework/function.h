#pragma once
void printArr(int L, int* Array);
void square(int* element);
void doubled(int* element);
int* filterEven(const int* source, int size, int& newSize);
int calculateSumInRange(const int* start, const int* end);
bool isEven(int num);
bool isPositive(int num);
int* readArr(int L, int* Array);
int* filterPositive(const int* source, int size, int& newSize);
const int* GetMin(const int* Array, int L);
void applyOperationArray(int* arr, int size, void (*operation)(int*));