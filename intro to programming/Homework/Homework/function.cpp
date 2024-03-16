#include <iostream>
#include "function.h";
using std::endl;
using std::cout;
using std::cin;

void square(int* element) {
    *element = (*element) * (*element);
}
int* readArr(int L, int* Array)
{
    for (int i = 0; i < L; ++i)
    {
        cin >> Array[i];
    }
    cout << endl;
    return Array;
}
void printArr(int L, int* Array)
{
    for (int i = 0; i < L; ++i)
    {
        cout << "[ " << Array[i] << "]";
    }
    cout << endl;

}
void doubled(int *element) {
    *element = *element * 2;
}
int* filterEven(const int* source, int size, int& newSize) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (isEven(source[i])) {
            ++count;
        }
    }

    int* resultArray = new int[count];
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (isEven(source[i])) {
            resultArray[index++] = source[i];
        }
    }

    newSize = count;
    return resultArray;
}

int calculateSumInRange(const int* start, const int* end) {
    int sum = 0;

    while (start != end) {
        sum += *start;
        ++start;
    }

    return sum;
}
bool isEven(int num)
{
    return num % 2 == 0;
}
bool isPositive(int num)
{
    return num > 0;
}
int* filterPositive(const int* source, int size, int& newSize) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (isPositive(source[i])) {
            ++count;
        }
    }

    int* resultArray = new int[count];
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (isPositive(source[i])) {
            resultArray[index++] = source[i];
        }
    }

    newSize = count;
    return resultArray;
}
const int* GetMin(const int* Array, int L)
{
    const int* MinAddress = Array;
    int min = Array[0];
    for (int i = 1; i < L; ++i)
    {
        if (min > Array[i])
        {
            min = Array[i];
            MinAddress = &Array[i];
        }
    }
    return MinAddress;
}
void applyOperationArray(int* arr, int size, void (*operation)(int*)) {
    for (int i = 0; i < size; ++i) {
        operation(&arr[i]);
    }
}