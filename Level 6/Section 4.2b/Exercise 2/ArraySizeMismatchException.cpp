#include "ArraySizeMismatchException.h"
#include <sstream>
ArraySizeMismatchException::ArraySizeMismatchException() :ArrayException()//default constructor
{
	size1 = 0;
	size2 = 0;
	cout << "Default constructor for ArraySizeMismatchException" << endl;
}

ArraySizeMismatchException::ArraySizeMismatchException(const ArraySizeMismatchException& e) : ArrayException(e)//copy constructor
{
	cout << "Copy constructor for ArraySizeMismatchException" << endl;
	size1 = e.size1;
	size2 = e.size2;
}

ArraySizeMismatchException::ArraySizeMismatchException(int s1,int s2) :ArrayException()// parametrized constructor alongwith base class constructor call
{
	cout << "Parametrized constructor for ArraySizeMismatchException" << endl;
	this->size1 = s1;// assigning the size 1
	this->size2 = s2;//assigning the size 2
}

ArraySizeMismatchException::~ArraySizeMismatchException()//destructor
{
	cout << "Array Size Mismatch Destructor is called" << endl;
}

ArraySizeMismatchException& ArraySizeMismatchException::operator=(const ArraySizeMismatchException& e)
{
	cout << "Assignment operator for ArraySizeMismatchException" << endl;
	if (this == &e) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}

	size1 = e.size1;
	size2 = e.size2;
	return *this;
}

string ArraySizeMismatchException::GetMessage() const
{
	ostringstream temp;
	temp << "This is an array size mismatch exception for the class type : " << ArrayException::GetMessage() << "Because one size is " << size1 << "and the other size is "<<size2 << endl;
	return temp.str();

}
