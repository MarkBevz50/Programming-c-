#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "mystack.h"
using namespace std;


//namespace Test
//{
//	double value = 5.0;
//	void f() { cout << "Test value: " << value << endl; }
//
//}
//
//namespace PMI
//{
//
//	double value = 87.5;
//	void f() { cout << "PMI-11 avg score: " << value << endl; }
//
//}
//
//using namespace Test;
//using namespace PMI;




int main()
{

	Stack::push(99);
	Stack::push(77);
	cout << "Top: " << Stack::peek() << endl;
	Stack::pop();
	cout << "Top: " << Stack::peek() << endl;
	
	while (!Stack::isFull())
	{
		int item;
		cout << "Enter value :"; cin >> item;
		Stack::push(item);

	}

	cout << "All values:\n";
	while (!Stack::isEmpty())
	{
		cout << Stack::peek() << endl;
		Stack::pop();
	}
	cout << endl;












	/*double start = - 3;
	double end = 1;
	double step = 0.1;
	cout.setf(ios_base::right, ios_base::adjustfield);
	cout.width(3); cout << "y";
	cout << " = ";
	cout.setf(ios_base::left, ios_base::adjustfield);
	cout << "4*x^3 - 2x^2 + 5 \n";
	cout.setf(ios_base::fixed, ios_base::floatfield);
	for (double x = start; x <= end; x += step)
	{
		cout.setf(ios_base::right, ios_base::adjustfield);
		double y = 4 * pow(x, 3) - 2 * pow(x, 2) + 5;
		cout.width(6); cout.precision(2); cout << x;
		cout << " : ";
		cout.setf(ios_base::left, ios_base::adjustfield);
		cout.width(8); cout.precision(4); cout << y;
		cout << endl;
	}
	cout << endl;*/

	return 0;
}



