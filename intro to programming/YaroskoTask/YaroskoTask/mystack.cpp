#include "mystack.h";
namespace Stack
{
	const size_t capacity = 10;
	size_t count = 0;
	int arr[capacity];
	void push(int value)
	{
		arr[count] = value;
		++count;
	}
	int peek()
	{
		return arr[count - 1];
	}
	void pop()
	{
		--count;
	}
	bool isEmpty()
	{
		return count == 0;
	}
	bool isFull()
	{
		return count == capacity;

	}

}