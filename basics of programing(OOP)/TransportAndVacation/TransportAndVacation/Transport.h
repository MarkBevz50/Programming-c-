#pragma once
#include <iostream>
#include <string>
class Transport
{
protected:
	int engine_power;
	std::string brand;
public:
	Transport();
	Transport(std::string brand, int engine_power);
	Transport(const Transport& T);
	std::string getBrand()const;
	virtual double getUsageCost()const abstract;
	virtual Transport* clone()const abstract;
	virtual void print() const abstract;
	virtual void writeTo(std::ostream& out) const;
	virtual void readFrom(std::istream& in);
	virtual ~Transport() {};
};
std::ostream& operator<<(std::ostream& out, const Transport& T);
std::istream& operator>>(std::istream& in, Transport& T);