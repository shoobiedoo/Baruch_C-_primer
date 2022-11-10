
#ifndef ARRAYEXCEPTION_H
#define ARRAYEXCEPTION_H
#include <iostream>
using namespace std;
class ArrayException//base exception class for arrays
{
private:
	int index;
public:
	ArrayException(); // Default constructor
	//ArrayException(const ArrayException& p); copy constructor does not make sense as class has no attributes to itself
	~ArrayException(); // Destructor
	//ArrayException& operator = (const ArrayException& source); // Assignment operator not required as there is no Assignment required as class as no attributes

	virtual string GetMessage() const;//defined virtual so that derived class is able to override this 
};
#endif

