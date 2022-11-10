
#ifndef OUTOFBOUNDSEXCEPTION_H
#define OUTOFBOUNDSEXCEPTION_H
#include <iostream>
#include "ArrayException.h"
using namespace std;
class OutOfBoundsException : public ArrayException // outofbouds inheriting ArrayException
{
private : 
	int index;//to know what index was at fault
public : 
	OutOfBoundsException(); // Default constructor
	OutOfBoundsException(const OutOfBoundsException& e);//copy constructor
	OutOfBoundsException(int index);//parametrized constructor
	~OutOfBoundsException(); // Destructor

	OutOfBoundsException& operator = (const OutOfBoundsException& source); // Assignment operator.

	string GetMessage() const;//Get message function which will override the base class method
};
#endif

