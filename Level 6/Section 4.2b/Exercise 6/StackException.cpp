#include "StackException.h"
#include <sstream>
StackException::StackException() //default constructor
{
	index = 0;
	cout << "Default constructor for StackException" << endl;
}

StackException::~StackException()//destructor
{
	cout << "Stack Destructor is called" << endl;
}

string StackException::GetMessage() const
{
	ostringstream temp;
	temp << "StackException";
	return temp.str();

}
