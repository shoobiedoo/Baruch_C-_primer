// Line.h
// (Finite) line segments in 2 dimensions. This class represents an undirected
// line segment.
// The functionality is basic. 


#ifndef Line_HPP
#define Line_HPP

#include "Point.h"
#include <iostream>
using namespace std;

class Line
{
private:

	Point startPoint;	// starting point of the line
	Point endPoint;		// ending point of the line

public:

	// Constructors
	Line();									// Line with both end Points at the origin
	Line(const Point& p1, const Point& p2);	// Line with end Points [p1, p2]
	Line(const Line& l); 					// Copy constructor
	virtual ~Line();						// Destructor

	// Accesssing/Getter functions which are overloaded
	Point start() const;
	Point end() const;

	// Modifiers
	void start(const Point& pt);					// Set Point pt1
	void end(const Point& pt);						// Set Point pt2

	//Calculation and Display Methods
	double Length() const;							// Length of line
	string ToString() const;						// Description of line
};

#endif




