#pragma once
#ifndef VISITOR_H
#define VISITOR_H
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "boost/variant.hpp"
#include <iostream>
//inheriting from the static visitor
class Visitor : public boost::static_visitor<void>
{
private:
    double m_dx;  //x-offset
    double m_dy;  //y-offset

public:
	// Constructors and destructor
	Visitor(); // Default constructor
	Visitor(const Visitor& v);
	Visitor(double xval, double yval);
	~Visitor(); // Destructor
	//Selectors
	double M_DX() const; // Access the x offset value
	double M_DY() const; // Access the y offset value
	// Modifiers
	void M_DX(double newxval); // Set the x offset value
	void M_DY(double newyval); // Set the y offset value
//Operator() overloading for different Shapes
	void operator () (Point & p) const;
	void operator () (Line& p) const;
	void operator () (Circle& c) const;
	Visitor& operator = (const Visitor& p);//overloafding the assignment operator
};
#endif
