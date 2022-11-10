#include "OutOfBoundsException.h"
#include <sstream>
OutOfBoundsException::OutOfBoundsException() :ArrayException()//default constructor
{
	cout << "Default constructor for OutOfBoundsException" << endl;
}

OutOfBoundsException::OutOfBoundsException(const OutOfBoundsException& e) : ArrayException(e)//copy constructor
{
	cout << "Copy constructor for OutOfBoundsException" << endl;
	index = e.index;
}

OutOfBoundsException::OutOfBoundsException(int ind) :ArrayException()// parametrized constructor alongwith base class constructor call
{
	cout << "Parametrized constructor for OutOfBoundsException" << endl;
	index = ind;// assigning the index
}

OutOfBoundsException::~OutOfBoundsException()//destructor
{
	cout << "OutofBounds Destructor is called" << endl;
}

OutOfBoundsException& OutOfBoundsException::operator=(const OutOfBoundsException& e)
{
	cout << "Assignment operator for OutOfBoundsException" << endl;
	if (this == &e) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}

	index = e.index;
	return *this;
}

string OutOfBoundsException::GetMessage() const
{
	ostringstream temp;
	temp << "This is an out of bounds exception for the class type : " << ArrayException::GetMessage() << "Because the index " << index << "is out of range" << endl;
	return temp.str();

}
