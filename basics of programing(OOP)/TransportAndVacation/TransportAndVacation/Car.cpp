#include "Car.h"
Car::Car()
	:Transport("Toyota", 100),fuel_consumption_100(9)
{
}
Car::Car(std::string brand, int engine_power, double fuel_consumption_100)
	:Transport(brand, engine_power), fuel_consumption_100(fuel_consumption_100)
{
}
Car::Car(const Car& C)
	:Transport(C.brand, C.engine_power), fuel_consumption_100(C.fuel_consumption_100)
{
}
double Car::getUsageCost() const
{
	return fuel_consumption_100 * petrol_price;
}
Car* Car::clone() const
{
	return new Car(*this);
}
void Car::print() const
{
	std::cout << "Car:" << std::endl;
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Engine Power: " << engine_power << std::endl;
	std::cout << "Fuel Consumption per 100km: " << fuel_consumption_100 << std::endl;
	std::cout << "Usage price: " << getUsageCost() << std::endl;
}
void Car::writeTo(std::ostream& out) const {
	Transport::writeTo(out);
	out << fuel_consumption_100 << std::endl;
}
void Car::readFrom(std::istream& in) {
	Transport::readFrom(in);
	in >> fuel_consumption_100;
}