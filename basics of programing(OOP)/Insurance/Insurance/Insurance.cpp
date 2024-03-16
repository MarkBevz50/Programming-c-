#include "Insurance.h"

std::istream& operator>>(std::istream& in, insurance& i)
{
    i.readFrom(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const insurance& i)
{
    i.writeTo(out);
    return out;
}

insurance::insurance()
    :base_price(0)
{
}

insurance::insurance(int base_price)
    :base_price(base_price)
{
}

insurance::insurance(const insurance& ins)
    :base_price(ins.base_price)
{
}

insurance::~insurance()
{
}

int insurance::getPrice() const
{
    return base_price;
}

bool insurance::operator<(const insurance& i) const
{
    return calcFullPrice() < i.calcFullPrice();
}
