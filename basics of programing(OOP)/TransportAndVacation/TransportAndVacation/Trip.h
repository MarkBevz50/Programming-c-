#pragma once
#include "Car.h"
class Trip
{
protected:
	Transport* transport;
	std::string destination;
public:
	Trip();
	Trip(Transport* transport, const std::string& destination);
	virtual ~Trip();
	virtual double calculateCost() const abstract;
	virtual void writeTo(std::ostream& out) const;
	virtual void readFrom(std::istream& in);
	virtual Trip* clone() abstract; 
	Transport* getTransport();
	virtual void printInfo() const abstract;
};
std::ostream& operator<<(std::ostream& out, const Trip& trip);
std::istream& operator>>(std::istream& in, Trip& trip);