// point.cpp
#include "point.h"
#include <sstream>
#include <string>
#include <cmath>
Point::Point():Shape(), x(0), y(0)
{//Default constructor using colon however not an effective change alongwith calling shape constructor
	cout << "Point created using default constructor with x and y initialized to " << x << " " << y << endl;
}
Point::Point(const Point& p1):Shape(p1)//Copy Constructor to copy the coordinates from a point  alongwith the shape copy constructor
{
	x = p1.x;
	y = p1.y;
	cout << "Point created using copy constructor" << endl;
}

Point::Point(double newx, double newy) : Shape(),x(newx), y(newy)// Parameterized constructor along with the shape default constructor
{// Initialize using newx and newy
	cout << "Point created using parameterized constructor with x " << x << " y " << y << endl;
}
Point::~Point()
{// Destructor
	cout << "Point destroyed" << endl;//Display message of the destructor for checking the overall functionality of the point destructor
}

//operator overloading
Point& Point::operator = (const Point& p) 
{
	// Avoid doing assign to myself
	if (this == &p) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}
	Shape::operator = (p); // shape assignment overloading
	x = p.x;
	y = p.y;
	cout << "Assignment operator is used for assigning points" << endl;
	return *this;
}

Point Point::operator + (const Point& p2) const
{ // Add two Point numbers

	return Point(x + p2.x, y + p2.y); // Anonymous object
}
Point Point::operator - () const
{ // Subtract two Point numbers

	return Point(-x, -y);
}

Point Point::operator * (double scale) const
{ //Scale a point number

	return Point(x * scale, y * scale);
}

Point& Point::operator *= (double scale)
{

	Point tmp = (*this) * scale;
	*this = tmp;

	return *this;

}

bool Point::operator == (const Point& p) const {
	return (x == p.x) && (y == p.y);
}

double Point::X() const
{
	return x;
}
// Access the y value
double Point::Y() const
{
	return y;
}
// Modifiers
// Set the x value 
void Point::X(double newxval)//overloaded X function as setter
{
	x = newxval;
}
// Set the y value
void Point::Y(double newyval)//overloaded Y function as setter
{
	y = newyval;
}
//To string method for printing the description of the point itself
string Point::ToString() const {
	ostringstream temp;//defining the output string stream
	temp << "Point(" << x << "," << y << ")";//returning the description about the point's coordinates
	return temp.str();
}

double Point::Distance() const {//overloading method distance origin as distance
	return sqrt(x * x + y * y);//using the pythagoras theorem to calculate this distance of the current point from origin
}

double Point::Distance(const Point& p) const {//call by reference to avoid calling the copy constructor 
	return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));// using the pythagoras theorem here as well but here the lengths are calculated by taking the difference of respective coodinates
}

//operator overloading for << 
ostream& operator << (ostream& os, const Point& p) {
	os << p.ToString();
	return os;
}