#include "Transport.h"

Transport::Transport()
	:brand("Riksha"), engine_power(1)
{
}

Transport::Transport(std::string brand, int engine_power)
	:brand(brand), engine_power(engine_power)
{
}

Transport::Transport(const Transport& T)
	:brand(T.brand), engine_power(T.engine_power)
{
}

std::string Transport::getBrand() const
{
	return brand;
}
void Transport::writeTo(std::ostream& out) const {
	out << brand << " " << engine_power << " ";
}

void Transport::readFrom(std::istream& in) {
	in >> brand >> engine_power;
}

std::ostream& operator<<(std::ostream& out, const Transport& T)
{
	T.writeTo(out);
	return out;
}

std::istream& operator>>(std::istream& in, Transport& T)
{
	T.readFrom(in);
	return in;
}
