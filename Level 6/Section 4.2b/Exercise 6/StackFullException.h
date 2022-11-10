
#ifndef StackFullException_H
#define StackFullException_H
#include <iostream>
#include "StackException.h"
using namespace std;
class StackFullException : public StackException // outofbouds inheriting ArrayException
{
private:
	int index;//to know what index was at fault
public:
	StackFullException(); // Default constructor
	StackFullException(const StackFullException& e);//copy constructor
	StackFullException(int index);//parametrized constructor
	~StackFullException(); // Destructor

	StackFullException& operator = (const StackFullException& source); // Assignment operator.

	string GetMessage() const;//Get message function which will override the base class method
};
#endif

