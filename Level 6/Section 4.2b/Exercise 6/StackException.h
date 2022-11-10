
#ifndef STACKEXCEPTION_H
#define STACKEXCEPTION_H
#include <iostream>
using namespace std;
class StackException//base exception class for arrays
{
private:
	int index;
public:
	StackException(); // Default constructor
	//StackException(const StackException& p); copy constructor does not make sense as class has no attributes to itself
	virtual ~StackException(); // Destructor
	//StackException& operator = (const StackException& source); // Assignment operator not required as there is no Assignment required as class as no attributes
	virtual string GetMessage() const;//defined virtual so that derived class is able to override this 
};
#endif

