#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
class Geometry_Figure
{
public:
	/*virtual double calculate_area() const abstract;*/
	virtual void print_info() const abstract;
	virtual ~Geometry_Figure();
	virtual void readFrom(std::istream& in)abstract;
	virtual void writeTo(std::ostream& out)const abstract;
};
std::ostream& operator<<(std::ostream& os, const Geometry_Figure& shape);
 std::istream& operator>>(std::istream& is, Geometry_Figure& shape);
class Planimetric_figure: public Geometry_Figure
{
public:
    virtual double calculate_area() const abstract;
	virtual double calculate_perimeter() const abstract;
};
class Rectangle :public Planimetric_figure
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
	void readFrom(std::istream& in)override;
	virtual void writeTo(std::ostream& out)const override;
    double get_width() const { return width; }
    double get_height() const { return height; }
    
};
class Square :public Rectangle
{
public:
	Square();
	Square(double side);
	void print_info() const override;
	void readFrom(std::istream& in)override;
	virtual void writeTo(std::ostream& out)const override;
  
};
class Circle : public Planimetric_figure{
protected:
	double radius;

public:
	Circle();
	Circle(double r);
    
	double calculate_area() const override;
	double calculate_perimeter() const override;
	void print_info() const override;
	void readFrom(std::istream& in)override;
	void writeTo(std::ostream& out)const override;
    double get_radius() const { return radius; }
    
};
class Triangle : public Planimetric_figure
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
	void readFrom(std::istream& in)override;
	void writeTo(std::ostream& out)const override;
    double get_side1() const { return side1; }
    double get_side2() const { return side2; }
    double get_angle() const { return angle; }
};
class Rectangular_Triangle : public Triangle
{
public:
    Rectangular_Triangle();
    Rectangular_Triangle(double side1, double side2);
    void print_info() const override;
};
    class Stereometric_Figure : public Geometry_Figure
    {
    protected:
        double height ;
    public:
        Stereometric_Figure(double h);
        virtual double calculate_volume() const abstract;
        virtual double calculate_surface_area() const abstract;
        virtual double calculate_lateral_area() const abstract;
    };
    class Pyramidal: public Stereometric_Figure
    {
    public:
        Pyramidal(double h);
    
    };
    class Triangular_Pyramid : Pyramidal
    {
    protected:
        Triangle base_triangel;
    public:
        Triangular_Pyramid(const Triangle& base, double h);
        double calculate_volume() const override;
        double calculate_surface_area()const override;
        double calculate_lateral_area() const override;
        void print_info() const override;
        void readFrom(std::istream& in) override;
        void writeTo(std::ostream& out) const override;
    };
    class Quadrangular_Pyramid : public Pyramidal
    {
    protected:
        Rectangle base_rectangle;
    public:
        Quadrangular_Pyramid(const Rectangle& base, double h);
        double calculate_lateral_area() const override;
        double calculate_volume() const override;
        double calculate_surface_area()const override;
        void print_info() const override;
        void readFrom(std::istream& in) override;
        void writeTo(std::ostream& out) const override;
    };
    class Cylinder : public Stereometric_Figure
    {
    protected:
        Circle base_circle;
       
    public:
        Cylinder(const Circle& base, double h);
        double calculate_volume() const override;
        double calculate_surface_area() const override;
        double calculate_lateral_area() const override;
        void print_info() const override;
        void readFrom(std::istream& in) override;
        void writeTo(std::ostream& out) const override;
    };

    class Cone : public Pyramidal
    {
    protected:
        Circle base_circle;
    public:
        double calculate_volume() const override;
        double calculate_surface_area() const override;
        double calculate_lateral_area() const override;
        void print_info() const override;
        void readFrom(std::istream& in) override;
        void writeTo(std::ostream& out) const override;
    };

    class Rectangular_Parallelipiped : public Stereometric_Figure
    {
    protected:
        Rectangle base_rectangle;
    public:
        double calculate_volume() const override;
        double calculate_surface_area() const override;
        double calculate_lateral_area() const override;
        void print_info() const override;
        void readFrom(std::istream& in) override;
        void writeTo(std::ostream& out) const override;
    };

    

    class Triangular_Prism : public Stereometric_Figure
    {
    protected:
        Triangle base_triangel;
    public:
        double calculate_volume() const override;
        double calculate_surface_area() const override;
        double calculate_lateral_area() const override;
        void print_info() const override;
        void readFrom(std::istream& in) override;
        void writeTo(std::ostream& out) const override;
    };

    class Node {
    public:
        Geometry_Figure* data;
        Node* next;
        Node(Geometry_Figure* val);
    };
    class GeometryContainer {
    private:
        Node* head;
    public:
        GeometryContainer();
        GeometryContainer(std::initializer_list<Geometry_Figure*> figures);
        GeometryContainer(const GeometryContainer& other);
        ~GeometryContainer();
        GeometryContainer& operator=(const GeometryContainer& other);
        void addFigure(Geometry_Figure* figure);
        void PrintNode(const Node* node)const;
        void insertFigure(size_t index, Geometry_Figure* figure);
        void removeFigure(size_t index);
        void removeAllFigures();
        Geometry_Figure* getFigure(size_t index) const;
        size_t size() const;

        void forEachFigure(void (*action)(Geometry_Figure* figure)) const;
        Geometry_Figure* findFirstFigure(bool (*criteria)(Geometry_Figure* figure)) const;
    };