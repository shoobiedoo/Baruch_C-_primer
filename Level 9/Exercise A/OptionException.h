
#ifndef OptionException_H
#define OptionException_H

#include <iostream>
using namespace std;

class OptionException
{
public:
	// Constructor and destructor
	OptionException()
	{ // Default constructor
	}

	virtual ~OptionException()
	{ // Destructor
	}

	virtual string GetMessage() = 0;
};

#endif