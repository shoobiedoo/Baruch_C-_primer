#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Shape.h"
int main() {
	Shape s; // Create shape.
	Point p(10, 20); // Create point.
	Line l(Point(1, 2), Point(3, 4)); // Create line.
	cout << s.ToString() << endl; // Print shape. 
	cout << p.ToString() << endl; // Print point.
	cout << l.ToString() << endl; // Print line
	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work?
	cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work?
	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible?
	cout << sp->ToString() <<"The point toString is called" << endl; // Because the ToString in shape is virtual the point ToString is called 
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.ID() << endl; // Is the ID copied if you do not call
	// the base class assignment in point
	/*
	* The id is only copied if you call the base class assignment in point otherwise not
	*/
	return 0;
}