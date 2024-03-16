#include "Exam.h"
int isNegative(int arr[], int n, int partOfArr)
{
    int Negative = 0;
    switch (partOfArr)
    {
    case 0:
        for (size_t i = 0; i < n; ++i)
        {
            if (arr[i] < 0)
                ++Negative;

        }
        break;
    case 1:
        for (size_t i = 0; i < n / 2; ++i)
        {
            if (arr[i] < 0)
                ++Negative;
        }
        break;
    case 2:
        for (size_t i = n / 2; i < n; ++i)
        {
            if (arr[i] < 0)
                ++Negative;
        }
        break;
    default:
        break;
    }
    return Negative;
}
int* createArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    return arr;
}

void printArray(int arr[], int n)
{
        for (int i = 0; i < n; ++i)
        {
            std::cout << arr[i] << ' ';
        }
}

bool operator<(const Auditoriums& T, const Auditoriums& P)
{
    return T.calculateArea() < P.calculateArea();
}

std::istream& operator>>(std::istream& in, Auditoriums& T)
{
    in >> T.number >> T.width >> T.length;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Auditoriums& T)
{
    out << T.number << ' ' << T.width << ' ' << T.length;
    return out;
}
Auditoriums* CreateArr(int n)
{
    Auditoriums* arr = new Auditoriums[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    return arr;
}

void printArrr(Auditoriums* arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        arr[i].print();
        std::cout << std::endl;
    }
}

int countAudithoriesOnThirdFloor(Auditoriums* arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i].defineFloar() == 3)
            count++;
    }
    return count;
}

Auditoriums findLargestAudithory(Auditoriums* arr, int n)
{
    Auditoriums largest = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i].calculateArea() > largest.calculateArea())
        {
            largest = arr[i];
        }
    }
    return largest;
}

int Auditoriums::calculateArea()const
{
    return width * length;
}

int Auditoriums::defineFloar()const
{
    return number / 100;
}

int Auditoriums::getNumber()const
{
    return number;
}

int Auditoriums::getWidth()const
{
    return width;
}

int Auditoriums::getLength()const
{
    return length;
}

void Auditoriums::setNumber(int new_number)
{
    number = new_number;
}

void Auditoriums::setWidth(int new_width)
{
    width = new_width;
}

void Auditoriums::setLength(int new_length)
{
    length = new_length;
}
void Auditoriums::print()
{
        std::cout << "nember: " << number << ' ' <<"width: "<< width << ' ' << "length: " << length << '\n';
}
Auditoriums::Auditoriums()
    :number(000), width(10), length(20)
{
}

Auditoriums::Auditoriums(int number, int width, int lenghth)
    :number(number), width(width), length(length)
{
}

Auditoriums::Auditoriums(const Auditoriums& T)
    :number(T.number), width(T.width), length(T.length)
{
}

Auditoriums::~Auditoriums()
{
}
