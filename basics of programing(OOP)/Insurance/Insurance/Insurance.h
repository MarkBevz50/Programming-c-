#pragma once
#include <iostream>

#include <fstream>
class  insurance  
{
protected:
	int base_price;
public:
	insurance() ;
	insurance(int base_price);
	insurance(const insurance& ins);
	virtual ~insurance();
	virtual insurance* clone() const abstract;
	int getPrice()const;
	virtual void printInfo()const abstract;
	bool operator < (const insurance& i) const;
	virtual void readFrom(std::istream& in) abstract;
	virtual int calcFullPrice() const abstract;
	virtual void writeTo(std::ostream& out) const abstract;
};
std::istream& operator >> (std::istream& in, insurance& i);
std::ostream& operator <<(std::ostream& out, const insurance& i);


