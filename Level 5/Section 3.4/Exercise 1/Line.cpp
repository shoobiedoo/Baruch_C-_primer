// MP Implementation of the Line segment .cpp

#include "Line.h"
#include <sstream>
#include <string>
#include <cmath>



Line::Line() : startPoint(),endPoint()//using colon syntax instead of assigning inside the default constructor 
{
	cout << "Default Constructor which initialises both point to (0,0)"<<endl;
}

Line::~Line()
{
	cout << "Line Destroyed" << endl;
}

Line::Line(const Point& p1, const Point& p2) : startPoint(p1),endPoint(p2) //parameterized constructor using colon syntax
{
	cout << "Parametrized constructor which initialised both points to " << startPoint << " " << endPoint << endl;
}

Line::Line(const Line& l) // copy constructor
{
	startPoint = l.startPoint;
	endPoint = l.endPoint;
}
//assignment operator overloading as in the canonical header file
Line& Line::operator = (const Line& l)
{
	// Avoid doing assign to myself
	if (this == &l) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}

	startPoint = l.startPoint;
	endPoint = l.endPoint;
	cout << "Assignment operator is used for assigning lines" << endl;
	return *this;
}
const Point& Line::start() const //overloaded getter for the startpoint
{
	return startPoint;
}

const Point& Line::end() const //overloaded getter for the endpoint
{
	return endPoint;
}

void Line::start(const Point& pt) // overloaded setter for the start point
{
	startPoint = pt;
}

void Line::end(const Point& pt) // overloaded setter for the end point
{
	endPoint = pt;
}

double Line::Length() const {//returns the length of the line by using the underlying distance method attached to the starting point object
	return startPoint.Distance(endPoint);//using the embedded distance method in the point object
}

string Line::ToString() const {
	ostringstream temp;
	temp << "Line(" << startPoint.ToString() << "," << endPoint.ToString() << ")" << endl;
	return temp.str();
}

//operator overloading for << 
ostream& operator << (ostream& os, const Line& l) {
	os << l.ToString();
	return os;
}