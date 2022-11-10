#include "StackFullException.h"
#include <sstream>
StackFullException::StackFullException() : StackException()//default constructor
{
	index = INT_MAX;//defining it to the max possible stack size
	cout << "Default constructor for StackFullException" << endl;
}

StackFullException::StackFullException(const StackFullException& e) : StackException(e)//copy constructor
{
	cout << "Copy constructor for StackFullException" << endl;
	index = e.index;
}

StackFullException::StackFullException(int ind) :StackException()// parametrized constructor alongwith base class constructor call
{
	cout << "Parametrized constructor for StackFullException" << endl;
	index = ind;// assigning the index
}

StackFullException::~StackFullException()//destructor
{
	cout << "OutofBounds Destructor is called" << endl;
}

StackFullException& StackFullException::operator=(const StackFullException& e)
{
	cout << "Assignment operator for StackFullException" << endl;
	if (this == &e) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}

	index = e.index;
	return *this;
}

string StackFullException::GetMessage() const
{
	ostringstream temp;
	temp << "This is a stack overflow for the class type : " << StackException::GetMessage() << " Because the index at which you are trying to push is : " << index << " which is >= the size of the stack. "<< endl;
	return temp.str();

}
