// point.cpp
#include "point.h"
#include <sstream>
#include <string>
#include <cmath>
Point::Point()
{//Default constructor
	x = 0;
	y = 0;
	cout << "Point created using default constructor" << endl;
}
Point::Point(const Point& p1)//Copy Constructor to copy the coordinates from point 1
{
	x = p1.x;
	y = p1.y;
	cout << "Point created using copy constructor" << endl;
}

Point::Point(double newx, double newy)// Parameterized constructor
{// Initialize using newx and newy
	x = newx;
	y = newy;
	cout << "Point created using parameterized constructor" << endl;
}
Point::~Point()
{// Destructor
	cout << "Point destroyed" << endl;//Display message of the destructor for checking the overall functionality of the point destructor
}

//To string method for printing the description of the point itself
string Point::ToString() {
	ostringstream temp;//defining the output string stream
	temp << "Point(" << x << "," << y << ")" << endl;//returning the description about the point's coordinates
	return temp.str();
}

double Point::Distance() {//overloading method distance origin as distance
	return sqrt(x * x + y * y);//using the pythagoras theorem to calculate this distance of the current point from origin
}

double Point::Distance(const Point& p) {//call by reference to avoid calling the copy constructor 
	return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));// using the pythagoras theorem here as well but here the lengths are calculated by taking the difference of respective coodinates
}