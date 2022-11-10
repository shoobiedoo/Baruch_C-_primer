//Implementation of the Circle  Circle.cpp
#define _USE_MATH_DEFINES
#include "Circle.h"
#include <sstream>
#include <string>
#include <cmath>


Circle::Circle()
{
	cPoint = Point(0, 0);
	cout << "Default Constructor which initialises center point to (0,0)";

}

Circle::~Circle()
{
	cout << "Circle Destroyed" << endl;
}

Circle::Circle(double r, const Point& pt)//parameterized constructor
{
	radius = r;
	cPoint = pt;

}

Circle::Circle(const Circle& l) // copy constructor
{
	cPoint = l.cPoint;
	radius = l.radius;
}

//assignment operator overloading as in a canonical header file
Circle& Circle::operator = (const Circle& c)
{
	// Avoid doing assign to myself
	if (this == &c) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}

	radius = c.radius;
	cPoint = c.cPoint;

	return *this;
}


const Point& Circle::centerPoint() const //overloaded getter for the startpoint
{
	return cPoint;
}

double Circle::Radius() const //overloaded getter for the endpoint
{
	return radius;
}

void Circle::centerPoint(const Point& pt) // overloaded setter for the start point
{
	cPoint = pt;
}

void Circle::Radius(double r) // overloaded setter for the end point
{
	radius = r;
}

double Circle::Diameter() const {//returns the diameter of the Circle
	return 2 * radius;//multiplying the radius by 2
}

double Circle::Circumference() const { //returns the circumference of the circle , we use msoft's M_PI to get PI
	return 2 * M_PI * radius;
}

double Circle::Area() const {
	return M_PI * radius * radius; // returns the area of the circle
}
string Circle::ToString() const {
	ostringstream temp;
	temp << "Circle(" << cPoint.ToString() << ", Radius : " << radius << ")" << endl;//For description of the circle using the point's embedded ToString function
	return temp.str();
}
