#pragma once
int* readArr( int L, int* Array);
void printArr(int L, int* Array);
int* doubled(int L, const int* Array, void(*printArr)(int, int* ));
int* squared(int L, const int* Array, void(*printArr)(int, int* ));
bool isEven(int num);
bool isPositive(int num);
int* filterArray(const int* Array,int L,int& newSize,bool(*predicate)(int),void(*printArr)(int ,int* ));
int* filterArray2(const int* Array,int L,int& newSize,bool(*predicate)(int),void(*printArr)(int, int*));
const int* GetMin(const int* Array, int L);
int calculateSumInRange(const int* Array, int start, int end);
