#include <iostream>
#include <cmath>
#include "function.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int L;
	do {
		cout << "Enter lenghth of your array: ";
		cin >> L;
		if (L <= 0)
			cout << "Length cant be 0 or less.\n";
		else {
			break;
		}
	} while (true);
	int* Array = new int[L];
	cout << "Enter your array: \n";
	readArr(L, Array);
	cout << "Enter range of elements which sum you want.(from start to end) 0 is first index.";
	int start;
	int end;
	cin >> start >> end;
	cout << "Your Array is: ";
	printArr(L, Array);
	 cout << "Doubled array";
	 doubled(L, Array, printArr);
	 cout << "Squared array";
	 squared(L, Array, printArr);
	 cout << "Even Array:";
	 int newSize;
	 filterArray(Array, L, newSize,isEven, printArr);
	 cout << "Positive Array:";
	 filterArray2(Array, L, newSize, isEven, printArr);

	 GetMin( Array,  L);
	 const int* MinElement = GetMin(Array, L);
	 cout << "Min element of Array is [" << *MinElement << ']' << endl;
	  int Sum = calculateSumInRange( Array,  start,  end);

	  cout << "Sum of all elements from " << start << " to " << end << " is " << Sum << endl;
	  delete[] Array;
	return 0;
}