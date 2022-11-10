#include "ArrayException.h"
#include <sstream>
ArrayException::ArrayException() //default constructor
{
	index = 0;
	cout << "Default constructor for ArrayException" << endl;
}

ArrayException::~ArrayException()//destructor
{
	cout << "Array Destructor is called" << endl;
}

string ArrayException::GetMessage() const
{
	ostringstream temp;
	temp << "ArrayException";
	return temp.str();

}
