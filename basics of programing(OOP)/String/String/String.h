#pragma once
class String
{
private:
	 char* str;
	size_t length;
public:
	String();
	String(const char* str);
	String(const String& other);
	String(const char arr[], size_t size);
	~String();

	const char* getString()const;
	size_t getLength() const;
	bool isEmpty();

	void setString(const char* str);
	void setString(String& other);
	void setString(const char arr[], size_t size);
};
String createStringWithNumbers(const int arr[], size_t size);
char ConvertDigitToChar(int digit);