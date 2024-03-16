#include <iostream>
#include "function.h"

int main() {
    int L;
    do {
        std::cout << "Enter length of your array: ";
        std::cin >> L;
        if (L <= 0)
            std::cout << "Length can't be 0 or less.\n";
        else {
            break;
        }
    } while (true);
    int* Array = new int[L];
    std::cout << "Enter your array: \n";
    readArr(L, Array);
    std::cout << "Your Array is: ";
    printArr(L, Array);
   
    // Операція застосовується до оригінального масиву
    // Збереження оригінального масиву
    int* originalArray = new int[L];
    std::copy(Array, Array + L, originalArray);
    const int* minElement = GetMin(originalArray, L);
    std::cout << "Min element of Array is [" << *minElement << "]\n";
    int start, end;
    std::cout << "Enter range of elements for calculating the sum (from start to end, 0 is the first index): ";
    std::cin >> start >> end;
    // Операція застосовується до оригінального масиву
    int sum = calculateSumInRange(originalArray + start, originalArray + end + 1);
    std::cout << "Sum of all elements from " << start << " to " << end << " is " << sum << "\n";
    int newSize;
    int* evenArray = filterEven(originalArray, L, newSize);
    std::cout << "Even Array:\n";
    printArr(newSize, evenArray);
    delete[] evenArray;
    int* positiveArray = filterPositive(originalArray, L, newSize);
    std::cout << "Positive Array:\n";
    printArr(newSize, positiveArray);
    delete[] positiveArray;
    std::cout << "Doubled array:\n";
    // Операція застосовується до оригінального масиву
    applyOperationArray(originalArray, L, doubled);
    printArr(L, originalArray);
    // Знову відновлення оригінального масиву
    std::copy(Array, Array + L, originalArray);
    std::cout << "Squared array:\n";
    // Операція застосовується до оригінального масиву
    applyOperationArray(originalArray, L, square);
    printArr(L, originalArray);
    
    delete[] Array;
    delete[] originalArray; // Звільнення пам'яті для копії оригінального масиву
    return 0;
   
}
