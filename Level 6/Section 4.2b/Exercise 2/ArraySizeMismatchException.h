
#ifndef ARRAYSIZEMISMATCHEXCEPTION_H
#define  ARRAYSIZEMISMATCHEXCEPTION_H
#include <iostream>
#include "ArrayException.h"
using namespace std;
class ArraySizeMismatchException : public ArrayException // outofbouds inheriting ArrayException
{
private:
	int size1;//to know size of array 1
	int size2;// to know size of the other array
public:
	ArraySizeMismatchException(); // Default constructor
	ArraySizeMismatchException(const ArraySizeMismatchException& e);//copy constructor
	ArraySizeMismatchException(int size1,int size2);//parametrized constructor
	~ArraySizeMismatchException(); // Destructor

	ArraySizeMismatchException& operator = (const ArraySizeMismatchException& source); // Assignment operator.

	string GetMessage() const;//Get message function which will override the base class method
};
#endif

