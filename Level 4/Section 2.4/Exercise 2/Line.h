// Line.hpp
//
// (Finite) line segments in 2 dimensions. This class represents an undirected
// line segment.
// The functionality is basic. If you wish to get more functions then convert the
// line segment to a vector or to a line and use their respective member functions.
//
// This is a good example of Composition (a line segment consists of two points() 
// the Delegation principle. For example, the member fucntion that calculates the 
// length of a line is implemented as the distance function between the line's end
// points.
//
// Stripped version.
//
// (C) Datasim BV 1995-2011
//

#ifndef Line_HPP
#define Line_HPP

#include "Point.h"
#include <iostream>
using namespace std;

class Line
{
private:

	Point startPoint;	// e1
	Point endPoint;		// e2

public:

	// Constructors
	Line();									// Line with both end Points at the origin
	Line(const Point& p1, const Point& p2);	// Line with end Points [p1, p2]
	Line(const Line& l); 				// Copy constructor
	virtual ~Line();							// Destructor

	//Assignment operator as in the canonical header file
	Line& operator =  (const Line& c);

	// Accesssing functions
	const Point& start() const;
	const Point& end() const;

	// Modifiers
	void start(const Point& pt);					// Set Point pt1
	void end(const Point& pt);						// Set Point pt2

	//Calculation and Display Methods
	double Length() const;							// Length of line
	string ToString() const;						// Description of line
};

//declaring as a global function inside the header file but outside the class declaration
ostream& operator << (ostream& os, const Line& l);

#endif




