// Test program for the point class.
#include <iostream>
#include "point.h"
int main()
{
	const Point p1(1.5, 3.9);
	const Point p2(1.3, 3.6);
	/*
	* p1.x = 0; throws compiler error as p1 is const and we cant edit it
	*/
	cout << "The x coordinate of the const point 1 using a getter function " <<p1.X()<< endl;
	cout << "The y coordinate of the const point 1 using a getter function " <<p1.Y() << endl;
	cout << "The description of the const point 1 using a getter function " << p1.ToString() << endl;// printing the first point description
	cout << "The distance of const point 1 from origin is " << p1.Distance() << endl;//Printing the distance of point 1 from origin using overloaded function
	cout << "The description of const point 2 using ToString " << p2.ToString() << endl;//printing the second point description
	cout << "The distance of const point 1 from const point 2 is " << p1.Distance(p2) << endl;//Priting the distance of point 1 from point 2
	return 0;
}