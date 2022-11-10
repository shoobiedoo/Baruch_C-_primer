
#ifndef CIRCLE_H//avoiding mulitple inclusion
#define CIRCLE_H

#include "Point.h"
#include "Shape.h"
#include <iostream>
using namespace std;

class Circle : public Shape
{
private:
	double radius;//radius of the circle
	Point  cPoint;//center point of the circle

public:

	// Constructors
	Circle();									// Circle with center point at the origin with radius 0
	Circle(const double r, const Point& p);	// Circle with radius r and centerPoint p
	Circle(const Circle& l); 					// Copy constructor
	~Circle();							// Destructor

	//Assignment operator as in the canonical header file
	Circle& operator =  (const Circle& c);

	// Accessing functions
	const Point& centerPoint() const;						//Access the centerpoint
	double Radius() const;							//Access the radius
	// Modifiers
	void centerPoint(const Point& pt);				// Set Center Point pt
	void Radius(double radius);						// Set Radius of the circle

	//Calculation and Display Methods
	double Diameter() const;						// Diameter of Circle
	double Area() const;							// Area of the Circle
	double Circumference() const;					// Circumference of the Circle
	string ToString() const;						// Description of Circle
};

//declaring as a global function inside the header file but outside the class declaration
ostream& operator << (ostream& os, const Circle& c);
#endif




