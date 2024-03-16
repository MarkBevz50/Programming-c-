#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
class Geometry_Figure
{
public:
	virtual double calculate_area() const = 0;
	virtual double calculate_perimeter() const = 0;
	virtual void print_info() const = 0;
	virtual ~Geometry_Figure();
};
class Rectangle:public Geometry_Figure
{
protected:
	double width;
	double height;
public:
	Rectangle();
	Rectangle(double w, double h);
	double calculate_area() const override;
    double calculate_perimeter() const override;
    void print_info() const override;
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);
	friend std::istream& operator>>(std::istream& is, Rectangle& rectangle);
};
class Square :public Rectangle
{
public:
	Square();
	Square(double side);
	void print_info() const override;
	friend std::ostream& operator<<(std::ostream& os, const Square& square);
	friend std::istream& operator>>(std::istream& is, Square& square);
};
class Circle : public Geometry_Figure
{
protected:
	double radius;

public:
	Circle();
	Circle(double r);

	double calculate_area() const override;
    double calculate_perimeter() const override;
	void print_info() const override;
	friend std::ostream& operator<<(std::ostream& os, const Circle& circle);
	friend std::istream& operator>>(std::istream& is, Circle& circle);
};
class Triangle : public Geometry_Figure
{
protected:
	double side1;
	double side2;
	double angle;
public:
	
	Triangle();
	Triangle(double side1, double side2, double angle);
		double calculate_area() const override;
    double calculate_perimeter() const override;
	double calculate_side()const;
	void print_info() const override;
	friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle);
	friend std::istream& operator>>(std::istream& is, Triangle& triangle);
};
class Rectangular_Triangle : public Triangle
{
public:
	Rectangular_Triangle();
	Rectangular_Triangle(double side1, double side2);
	void print_info() const override;
	friend std::ostream& operator<<(std::ostream& os, const Rectangular_Triangle& rect_triangle);
	friend std::istream& operator>>(std::istream& is, Rectangular_Triangle& rect_triangle);
};
