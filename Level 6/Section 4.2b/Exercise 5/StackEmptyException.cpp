#include "StackEmptyException.h"
#include <sstream>
StackEmptyException::StackEmptyException() :StackException()//default constructor
{
	index = -1;
	cout << "Default constructor for StackEmptyException" << endl;
}

StackEmptyException::StackEmptyException(const StackEmptyException& e) : StackException(e)//copy constructor
{
	cout << "Copy constructor for StackEmptyException" << endl;
	index = e.index;
}

StackEmptyException::StackEmptyException(int ind) :StackException()// parametrized constructor alongwith base class constructor call
{
	cout << "Parametrized constructor for StackEmptyException" << endl;
	index = ind;// assigning the index
}

StackEmptyException::~StackEmptyException()//destructor
{
	cout << "OutofBounds Destructor is called" << endl;
}

StackEmptyException& StackEmptyException::operator=(const StackEmptyException& e)
{
	cout << "Assignment operator for StackEmptyException" << endl;
	if (this == &e) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}

	index = e.index;
	return *this;
}

string StackEmptyException::GetMessage() const
{
	ostringstream temp;
	temp << "This is a stack underflow for the class type : " << StackException::GetMessage() << " Because the index which you are trying to pop is : " << index <<" which is < 0 "<< endl;
	return temp.str();

}
