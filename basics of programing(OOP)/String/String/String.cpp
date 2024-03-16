#include "String.h"
#include <cstring>

String::String()
	: str(nullptr), length(0)
{
}

String::String(const char* str)
	: String()
{
	if (str && std::strlen(str) != 0)
	{
		length = std::strlen(str);
		this->length = length;
		this->str = new char[length + 1];
		strcpy_s(this->str, length + 1, str);
	}
}

String::String(const String& other)
	: String()
{
	if (other.length != 0)
	{
		this->length = other.length;
		str = new char [length + 1];
		strcpy_s(this->str,length+1, other.str);
	}
}

String::String(const char arr[], size_t size)
: String()
{
	if (arr != nullptr && size != 0)
	{
		length = size;
		str = new char[length + 1];

		for (size_t i = 0; i < length; ++i)
		{
			str[i] = arr[i];
		}
		str[length] = '\0';
    }
}

String::~String()
{
	delete[] str;
	str = nullptr;
	length = 0;
}

size_t String::getLength() const
{
	return length;
}

bool String::isEmpty()
{
	return length == 0;
}

void String::setString(const char* str)
{
	if (str && std::strlen(str) != 0)
	{
		size_t length = std::strlen(str);
		delete[] this->str;
		this->length = length;
		this->str = new char[length + 1];
		strcpy_s(this->str, length + 1, str);
	}
}

void String::setString(String& other)
{
	if (other.length != 0)
	{
		delete[] str;

		this->length = other.length;
		this->str = new char[length + 1];
		strcpy_s(this->str, length + 1, str);


	}
}

void String::setString(const char arr[], size_t size)
{
	if (arr != nullptr && size != 0)
	{
		delete[] str;
		length = size;
		str = new char[length + 1];

		for (size_t i = 0; i < length; ++i)
		{
			str[i] = arr[i];
		}
		str[length] = '\0';
	}
}

const char* String::getString() const
{
	return str != nullptr ? str : "";
}

String createStringWithNumbers(const int arr[], size_t size)
{
	if (arr == nullptr || size == 0)
		return String();

	char* str = new char[size + 1];
	

		for (size_t i = 0; i < size; ++i)
		{
			char convertedDigit = ConvertDigitToChar(arr[i]);
			str[i] = convertedDigit;
	    }
		str[size] = '\0';
		String object{ str };
		delete[] str;
	return object;
}

char ConvertDigitToChar(int digit)
{
	return digit >= 0 && digit <= 9 ? digit + '0' : '!';
}
