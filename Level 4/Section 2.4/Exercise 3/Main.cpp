// Test program for the point class.
#include <iostream>
#include "point.h"

int main()
{
	/*
	Comparing implicit and explicit conversion for objects using constructors
	*/

	/*
	Point p(1.0, 1.0);
	if (p == 1.0) cout << "Equal!" << endl; //implicit type casting will fail as the constructor is defined as explicit in the header file
	else cout << "Not equal" << endl;
	*/

	Point p(1.0, 1.0);
	if (p == (Point)1.0) cout << "Equal!" << endl; //explicit type casting as the constructor is defined as explicit in the header file
	else cout << "Not equal" << endl;

	return 0;
}