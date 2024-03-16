#include "Figures.h"
int main()
{
	Rectangle rectangle;
	std::cin >> rectangle;
	rectangle.print_info();
	Square square;
	std::cin >> square;
	std::cout << square;
	Circle circle;
	std::cin >> circle;
	std::cout << circle;
	Triangle triangle;
	std::cin >> triangle;
	triangle.print_info();
	Rectangular_Triangle A;
	std::cin >> A;
	A.print_info();
	return 0;
}