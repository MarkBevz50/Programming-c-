#include "Exam.h"
int main()
{
	int Arr[7] = { 10, -5, -2, -6, 11, 23 , -10 };  // Cтворюємо довільний масив щоб показати як працює функія isNegative
    printArray(Arr, 7);
	int allNegative = isNegative(Arr, 7, 0);
	std::cout << "There is " << allNegative << " negative numbers" << '\n';
	std::cout << "Entere size of array: " ;
	int n;
	std::cin >> n;
	int* ourArr = new int[n];       // Оголошуємо власний динамічний масив розміру n
	ourArr = createArr(ourArr, n); // Створюємо його
	printArray(ourArr, n);
    std::cout << std::endl;
	std::cout << "Choose half of the array(0 - whole array, 1 - first half, 2 - second half):  " << '\n';
    int half;
    std::cin >> half;
    int NegativeInCertainHalf = isNegative(ourArr, n, half);
    std::cout << "There are " << NegativeInCertainHalf << " negative numbers in this half";
    const int s = 5;
    Auditoriums* arr = CreateArr(s);

    // Введення аудиторій та виведення їх на екран
    std::cout << "Entered Auditoriums:\n";
    printArrr(arr, s);

    // Знаходження та виведення кількості аудиторій на третьому поверсі
    int countOnThirdFloor = countAudithoriesOnThirdFloor(arr, s);
    std::cout << "Number of Auditoriums on the third floor: " << countOnThirdFloor << '\n';

    // Знаходження та виведення найбільшої аудиторії за площею
    Auditoriums largest = findLargestAudithory(arr, s);
    std::cout << "Largest Auditorium:\n" << largest << '\n';
    delete[]ourArr;
    delete[] arr; // Звільнення пам'яті

}
