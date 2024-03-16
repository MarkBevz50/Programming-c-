#include "Figures.h"
Geometry_Figure::~Geometry_Figure()
{
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle)
{
	os << "Rectangle - Width: " << rectangle.width << ", Height: " << rectangle.height << ", Area: " << rectangle.calculate_area() << ", Perimeter: " << rectangle.calculate_perimeter() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle) {
	std::cout << "Enter width of rectangle: ";
	is >> rectangle.width;
	std::cout << "Enter height of rectangle: ";
	is >> rectangle.height;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Square& square)
{
	os << "Square side: " << square.width  << ", Area: " << square.calculate_area() << ", Perimeter: " << square.calculate_perimeter() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Square& square)
{
	std::cout << "Enter square side: ";
	is >> square.width;
	square.height = square.width;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Circle& circle)
{
	os << "Circle radius: " << circle.radius << ", Area: " << circle.calculate_area() << ", Length: " << circle.calculate_perimeter() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Circle& circle)
{
	std::cout << "Enter circle radius: ";
	is >> circle.radius;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Triangle& triangle)
{
	os << "Triangel - side1 : " << triangle.side1 << "Triangel side2 : "<< triangle.side2 << ", Angle :" << triangle.angle <<", Area: " << triangle.calculate_area() << ", Perimeter : " << triangle.calculate_perimeter() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Triangle& triangle)
{
	std::cout << "Enter two sides of the triangle : ";
	is >> triangle.side1 >> triangle.side2;
	std::cout << "Enter angle between sides : ";
	is >> triangle.angle;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Rectangular_Triangle& rect_triangle)
{
	os << "Rectangular Triangel - side1: " << rect_triangle.side1 << ", Triangel side2: " << rect_triangle.side2 << ", Triangel side3: " << rect_triangle.calculate_side() << ", Area : " << rect_triangle.calculate_area() << ", Perimeter : " << rect_triangle.calculate_perimeter() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Rectangular_Triangle& rect_triangle)
{
	std::cout << "Enter two sides of the triangle : ";
	is >> rect_triangle.side1 >> rect_triangle.side2;
	return is;
}

Rectangle::Rectangle()
	:width(3), height(4)
{
}

Rectangle::Rectangle(double w, double h)
	:width(w),height(h)
{
}

double Rectangle::calculate_area() const
{
	return width * height;
}

double Rectangle::calculate_perimeter() const
{
	return 2*(width + height);
}

void Rectangle::print_info() const
{
	std::cout << "Rectangle - Width: " << width << ", Height: " << height << ", Area: "<<calculate_area() <<", Perimeter: "<<calculate_perimeter() << std::endl;
}

Square::Square()
	:Rectangle(4,4)
{
}

Square::Square(double side)
	:Rectangle(side, side)
{
}

void Square::print_info() const
{
	std::cout << "Square - side: " << width << ", Area: " <<calculate_area()<< ", Perimetr: " << calculate_perimeter()<< std::endl;
}

Circle::Circle()
	: radius(1)
{
}

Circle::Circle(double r)
	:radius(r)
{
}

double Circle::calculate_area() const
{
	return  M_PI * radius* radius ;
}

double Circle::calculate_perimeter() const
{
	return 2 * M_PI * radius;
}

void Circle::print_info() const
{
}

Triangle::Triangle()
	:side1(1), side2(2), angle(2)
{
}

Triangle::Triangle(double side1, double side2, double angle)
	:side1(side1), side2(side2), angle(angle)
{
}

double Triangle::calculate_area() const
{
	return 0.5 * side1 * side2 * sin(angle);
}

double Triangle::calculate_perimeter() const
{
	double side3 = calculate_side();
	return side1 + side2 + side3;
}

double Triangle::calculate_side()const
{
	double angle_rad;
	angle_rad = angle * M_PI / 180.0; 
	double side3;
	side3 = sqrt(side1 * side1 + side2 * side2 - 2 * side1 * side2 * cos(angle_rad));
	return side3;
}

void Triangle::print_info() const
{
	std::cout<< "Triangel - side1: " << side1 << ", Triangel side2: " << side2 <<", Triangel side3: " <<calculate_side() <<", Angle : " << angle << ", Area : " << calculate_area() << ", Perimeter : " << calculate_perimeter() << std::endl;
}

Rectangular_Triangle::Rectangular_Triangle()
	: Triangle(1, 2 , 90.0)
{
}

Rectangular_Triangle::Rectangular_Triangle(double side1, double side2)
	:Triangle(side1, side2, 90.0)
{
}

void Rectangular_Triangle::print_info() const
{
	std::cout << "Rectangular Triangel - side1: " << side1 << ", Triangel side2: " << side2 << ", Triangel side3: " << calculate_side() << ", Area : " << calculate_area() << ", Perimeter : " << calculate_perimeter() << std::endl;
}
