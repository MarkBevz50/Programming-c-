#include "Figures.h"
Geometry_Figure::~Geometry_Figure()
{
}


Rectangle::Rectangle()
	:width(3), height(4)
{
}

Rectangle::Rectangle(double w, double h)
	:width(w), height(h)
{
}

double Rectangle::calculate_area() const
{
	return width * height;
}

double Rectangle::calculate_perimeter() const
{
	return 2 * (width + height);
}

void Rectangle::print_info() const
{
	std::cout << "Rectangle - Width: " << width << ", Height: " << height << ", Area: " << calculate_area() << ", Perimeter: " << calculate_perimeter() << std::endl;
}

void Rectangle::readFrom(std::istream& in)
{
	in >> width >> height;
}

void Rectangle::writeTo(std::ostream& out) const
{
	out << width << height;
}

Square::Square()
	:Rectangle(4, 4)
{
}

Square::Square(double side)
	:Rectangle(side, side)
{
}

void Square::print_info() const
{
	std::cout << "Square - side: " << width << ", Area: " << calculate_area() << ", Perimetr: " << calculate_perimeter() << std::endl;
}

void Square::readFrom(std::istream& in)
{
	in >> width;
	height = width;
}

void Square::writeTo(std::ostream& out) const
{
	out << width;
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
	return  M_PI * radius * radius;
}

double Circle::calculate_perimeter() const
{
	return 2 * M_PI * radius;
}

void Circle::print_info() const
{
	std::cout << "Circle radius: " << radius << ", Area: " << calculate_area() << ", Length: " << calculate_perimeter() << std::endl;
}

void Circle::readFrom(std::istream& in)
{
	in >> radius;
}

void Circle::writeTo(std::ostream& out) const
{
	out << radius;
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
	std::cout << "Triangel - side1: " << side1 << ", Triangel side2: " << side2 << ", Triangel side3: " << calculate_side() << ", Angle : " << angle << ", Area : " << calculate_area() << ", Perimeter : " << calculate_perimeter() << std::endl;
}

void Triangle::readFrom(std::istream& in)
{
	in >> side1 >> side2 >> angle;
}

void Triangle::writeTo(std::ostream& out) const
{
	out << side1 << side2 << angle;
}

Rectangular_Triangle::Rectangular_Triangle()
	: Triangle(1, 2, 90.0)
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

std::ostream& operator<<(std::ostream& os, const Geometry_Figure& shape)
{
	shape.writeTo(os);
	return os;
}

std::istream& operator>>(std::istream& is, Geometry_Figure& shape)
{
	shape.readFrom(is);
	return is;
}

Stereometric_Figure::Stereometric_Figure(double h)
    : height(h)
{
}



Triangular_Pyramid::Triangular_Pyramid(const Triangle& base, double h)
    : Pyramidal(h), base_triangel(base)
{
    height = h;
}

double Triangular_Pyramid::calculate_lateral_area() const
{
    return (1.0 / 2) * base_triangel.calculate_perimeter() * height;
}

void Triangular_Pyramid::print_info() const
{
    std::cout << "Triangular Pyramid - Base: ";
    base_triangel.print_info();
    std::cout << ", Height: " << height << ", Volume: " << calculate_volume() << ", Surface Area: " << calculate_surface_area() << ", Lateral Area: " << calculate_lateral_area() << std::endl;
}

void Triangular_Pyramid::readFrom(std::istream& in)
{
    base_triangel.readFrom(in);
    in >> height;
}

void Triangular_Pyramid::writeTo(std::ostream& out) const
{
    base_triangel.writeTo(out);
    out << height;
}

//Rectangular_Triangle::Quadrangular_Pyramid::Triangular_Pyramid(const Triangle& base, double h)
//{
//}

double Quadrangular_Pyramid::calculate_lateral_area() const
{
    double basePerimeter = base_rectangle.calculate_perimeter();
    double lateralArea = basePerimeter * height;
    return lateralArea;
}

void Quadrangular_Pyramid::print_info() const
{
    std::cout << "Quadrangular Pyramid - Base: ";
    base_rectangle.print_info();
    std::cout << ", Height: " << height << ", Volume: " << calculate_volume() << ", Surface Area: " << calculate_surface_area() << ", Lateral Area: " << calculate_lateral_area() << std::endl;
}

void Quadrangular_Pyramid::readFrom(std::istream& in)
{
    base_rectangle.readFrom(in);
    in >> height;
}

void Quadrangular_Pyramid::writeTo(std::ostream& out) const
{
    base_rectangle.writeTo(out);
    out << height;
}


double Cylinder::calculate_volume() const
{
    return base_circle.calculate_area() * height; 
}

double Cylinder::calculate_surface_area() const
{
    return 2 * base_circle.calculate_area() + base_circle.calculate_perimeter() * height; 
}

double Cylinder::calculate_lateral_area() const
{
    return base_circle.calculate_perimeter() * height; 
}

void Cylinder::print_info() const
{
    std::cout << "Cylinder - Base: ";
    base_circle.print_info();
    std::cout << ", Height: " << height << ", Volume: " << calculate_volume() << ", Surface Area: " << calculate_surface_area() << ", Lateral Area: " << calculate_lateral_area() << std::endl;
}

void Cylinder::readFrom(std::istream& in)
{
    base_circle.readFrom(in);
    in >> height;
}

void Cylinder::writeTo(std::ostream& out) const
{
    base_circle.writeTo(out);
    out << height;
}

//Rectangular_Triangle::Cylinder::Quadrangular_Pyramid(const Rectangle& base, double h)
//{
//}
//
//Rectangular_Triangle::Cylinder::Cylinder(const Circle& base, double h)
//{
//}


double Cone::calculate_volume() const
{
    return base_circle.calculate_area() * height / 3.0; 
}

double Cone::calculate_surface_area() const
{
    double slant_height = sqrt(base_circle.get_radius() * base_circle.get_radius() + height * height);
    return M_PI * base_circle.get_radius() * slant_height; 
}

double Cone::calculate_lateral_area() const
{
    return base_circle.calculate_perimeter() * height / 2.0; 
}

void Cone::print_info() const
{
    std::cout << "Cone - Base: ";
    base_circle.print_info();
    std::cout << ", Height: " << height << ", Volume: " << calculate_volume() << ", Surface Area: " << calculate_surface_area() << ", Lateral Area: " << calculate_lateral_area() << std::endl;
}

void Cone::readFrom(std::istream& in)
{
    base_circle.readFrom(in);
    in >> height;
}

void Cone::writeTo(std::ostream& out) const
{
    base_circle.writeTo(out);
    out << height;
}

double Rectangular_Parallelipiped::calculate_volume() const
{
    return base_rectangle.calculate_area() * height; 
}

double Rectangular_Parallelipiped::calculate_surface_area() const
{
    return 2 * base_rectangle.calculate_area() + base_rectangle.calculate_perimeter() * height; 
}

double Rectangular_Parallelipiped::calculate_lateral_area() const
{
    return base_rectangle.calculate_perimeter() * height; 
}

void Rectangular_Parallelipiped::print_info() const
{
    std::cout << "Rectangular Parallelipiped - Base: ";
    base_rectangle.print_info();
    std::cout << ", Height: " << height << ", Volume: " << calculate_volume() << ", Surface Area: " << calculate_surface_area() << ", Lateral Area: " << calculate_lateral_area() << std::endl;
}

void Rectangular_Parallelipiped::readFrom(std::istream& in)
{
    base_rectangle.readFrom(in);
    in >> height;
}

void Rectangular_Parallelipiped::writeTo(std::ostream& out) const
{
    base_rectangle.writeTo(out);
    out << height;
}


double Triangular_Prism::calculate_volume() const
{
    return base_triangel.calculate_area() * height; 
}

double Triangular_Prism::calculate_surface_area() const
{
    return 2 * base_triangel.calculate_area() + base_triangel.calculate_perimeter() * height; 
}

double Triangular_Prism::calculate_lateral_area() const
{
    return base_triangel.calculate_perimeter() * height; 
}

void Triangular_Prism::print_info() const
{
    std::cout << "Triangular Prism - Base: ";
    base_triangel.print_info();
    std::cout << ", Height: " << height << ", Volume: " << calculate_volume() << ", Surface Area: " << calculate_surface_area() << ", Lateral Area: " << calculate_lateral_area() << std::endl;
}

void Triangular_Prism::readFrom(std::istream& in)
{
    base_triangel.readFrom(in);
    in >> height;
}

void Triangular_Prism::writeTo(std::ostream& out) const
{
    base_triangel.writeTo(out);
    out << height;
}

GeometryContainer::GeometryContainer()
{
}

GeometryContainer::GeometryContainer(std::initializer_list<Geometry_Figure*> figures)
{
}

GeometryContainer::GeometryContainer(const GeometryContainer& other)
{
}

GeometryContainer::~GeometryContainer()
{
}

GeometryContainer& GeometryContainer::operator=(const GeometryContainer& other)
{
    // TODO: insert return statement here
}

void GeometryContainer::addFigure(Geometry_Figure* figure)
{
}

void GeometryContainer::PrintNode(const Node* node) const
{
}

void GeometryContainer::insertFigure(size_t index, Geometry_Figure* figure)
{
}

void GeometryContainer::removeFigure(size_t index)
{
}

void GeometryContainer::removeAllFigures()
{
}

Geometry_Figure* GeometryContainer::getFigure(size_t index) const
{
    return nullptr;
}

size_t GeometryContainer::size() const
{
    return size_t();
}

void GeometryContainer::forEachFigure(void(*action)(Geometry_Figure* figure)) const
{
}

Geometry_Figure* GeometryContainer::findFirstFigure(bool(*criteria)(Geometry_Figure* figure)) const
{
    return nullptr;
}

Node::Node(Geometry_Figure* val)
{
}
