//Implementation of the Circle  Circle.cpp
#define _USE_MATH_DEFINES
#include "Circle.h"
#include <sstream>
#include <string>
#include <cmath>


Circle::Circle() : Shape(), radius(0), cPoint() // default constructor using colon syntax alongwith invoking Shape default constructor
{
	cout << "Default Constructor which initialises center point to" << cPoint << "and radius to " << radius << endl;

}

Circle::~Circle()
{
	cout << "Circle Destroyed" << endl;
}

Circle::Circle(double r, const Point& pt) : Shape(), radius(r), cPoint(pt) //parameterized constructor using colon syntax along with invoking Shape default constructor
{
	cout << "Parametrized Constructor which initialises center point to" << cPoint << "and radius to " << radius << endl;
}

Circle::Circle(const Circle& l) : Shape(l) // copy constructor along with invoking Shape copy constructor
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
	Shape :: operator = (c); // overloading the Shape assignment as well 
	radius = c.radius;
	cPoint = c.cPoint;
	cout << "Assignment operator is used for assigning circles" << endl;
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
	std::string s = Shape::ToString();//calling the shape's ToString function 
	temp << "Circle(" << cPoint.ToString() << ", Radius : " << radius << ")" << " Shape Description" << s << endl;//For description of the circle using the point's embedded ToString function and appending shape's to string function
	return temp.str();
}
//operator overloading for << 
ostream& operator << (ostream& os, const Circle& c) {
	os << c.ToString();
	return os;
}

//Draw method being overridden in Circle class
void Circle::Draw() const {
	cout << "Circle is drawn with radius " << radius << " center point : " << cPoint << endl;
}