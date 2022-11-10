
#ifndef StackEmptyException_H
#define StackEmptyException_H
#include <iostream>
#include "StackException.h"
using namespace std;
class StackEmptyException : public StackException // outofbouds inheriting ArrayException
{
private:
	int index;//to know what index was at fault
public:
	StackEmptyException(); // Default constructor
	StackEmptyException(const StackEmptyException& e);//copy constructor
	StackEmptyException(int index);//parametrized constructor
	~StackEmptyException(); // Destructor

	StackEmptyException& operator = (const StackEmptyException& source); // Assignment operator.

	string GetMessage() const;//Get message function which will override the base class method
};
#endif

