#pragma once
#include "Transport.h"
class Car :public Transport
{
private:
	double fuel_consumption_100;
	static const int petrol_price = 45;
public:
	Car();
	Car(std::string brand, int engine_power, double fuel_consumption_100);
	Car(const Car& C);
	double getUsageCost()const override;
	Car* clone()const override;
	void print() const override;
	void writeTo(std::ostream& out) const override;
	 void readFrom(std::istream& in) override;
};