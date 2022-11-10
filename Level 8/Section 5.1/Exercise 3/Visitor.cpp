// Visitor.cpp
#include "Visitor.h"
#include <sstream>
#include <string>
#include <cmath>
#include <iostream>
Visitor::Visitor() : m_dx(0), m_dy(0)
{//Default constructor using colon however not an effective change alongwith calling shape constructor
	cout << "Visitor created using default constructor with m_dx and m_dy initialized to " << m_dx << " " << m_dy << endl;
}
Visitor::Visitor(const Visitor& p1) //Copy Constructor to copy the coordinates from a Visitor  alongwith the shape copy constructor
{
	m_dx = p1.m_dx;
	m_dy = p1.m_dy;
	cout << "Visitor created using copy constructor" << endl;
}

Visitor::Visitor(double newx, double newy) : m_dx(newx), m_dy(newy)// Parameterized constructor along with the shape default constructor
{// Initialize using newx and newy
	cout << "Visitor created using parameterized constructor with m_dx " << m_dx << " m_dy " << m_dy << endl;
}
Visitor::~Visitor()
{// Destructor
	cout << "Visitor destroyed" << endl;//Display message of the destructor for checking the overall functionality of the Visitor destructor
}

//operator overloading
Visitor& Visitor::operator = (const Visitor& p)
{
	// Avoid doing assign to myself
	if (this == &p) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}
	m_dx = p.m_dx;
	m_dy = p.m_dy;
	cout << "Assignment operator is used for assigning Visitors" << endl;
	return *this;
}

double Visitor::M_DX() const
{
	return m_dx;
}
// Access the m_dy value
double Visitor::M_DY() const
{
	return m_dy;
}
// Modifiers
// Set the m_dx value 
void Visitor::M_DX(double newxval)//overloaded X function as setter
{
	m_dx = newxval;
}
// Set the m_dy value
void Visitor::M_DY(double newyval)//overloaded Y function as setter
{
	m_dy = newyval;
}
//overloading the () operator for the point object
void Visitor::operator () (Point& p) const
{
	p.X(p.X() + m_dx);// shifitng the point's coordinates by the offset
	p.Y(p.Y() + m_dy);
}
void Visitor::operator () (Line& l) const
{	//shifting both line points by the given offset
	//cant directly update the start point using getter as the returns a const point 
	l.start(Point(l.start().X() + m_dx, l.start().Y() + m_dy));
	l.end(Point(l.end().X() + m_dx, l.end().Y() + m_dy));
}
void Visitor::operator () (Circle& c) const
{
	//shifting the center point by the offset
	c.centerPoint(Point(c.centerPoint().X() + m_dx, c.centerPoint().Y() + m_dy));
	//cant use something like this c.CentrePoint().X(c.CentrePoint().X() + m_dx); as the  getter returns a const Point 
}