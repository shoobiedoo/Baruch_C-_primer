// MP Implementation of the Line segment .cpp

#include "Line.h"
#include <sstream>
#include <string>
#include <cmath>



Line::Line() : Shape(), startPoint(), endPoint()//using colon syntax instead of assigning inside the default constructor alongwith the shape default constructor
{
	cout << "Default Constructor which initialises both point to (0,0)" << endl;
}

Line::~Line()
{
	cout << "Line Destroyed" << endl;
}

Line::Line(const Point& p1, const Point& p2) : Shape(), startPoint(p1), endPoint(p2) //parameterized constructor using colon syntax alongwith the shape constructor
{
	cout << "Parametrized constructor which initialised both points to " << startPoint << " " << endPoint << endl;
}

Line::Line(const Line& l) : Shape(l)// copy constructor also invoking the shape constructor
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
	Shape::operator = (l); // overloading the shape assignment as well
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
	std::string s = Shape::ToString();//calling the shape's ToString function 
	temp << "Line(" << startPoint.ToString() << "," << endPoint.ToString() << ")" << " Shape Description" << s << endl;//appending shape's toString function
	return temp.str();
}

//operator overloading for << 
ostream& operator << (ostream& os, const Line& l) {
	os << l.ToString();
	return os;
}
//Draw method being drawn in Line class
void Line::Draw() const {
	cout << "Line is drawn with points " << startPoint << " " << endPoint << endl;
}