// point.h
// Simple two dimensional point consisting of a x and y 
// value

#ifndef POINT_H //to avoid multiple inclusion
#define POINT_H
#include <iostream>
using namespace std;
class Point
{
private:
	double x; // X value of point
	double y; // Y value of point
public:
	// Constructors and destructor
	Point(); // Default constructor
	Point(double xval, double yval);
	~Point(); // Destructor
	//Selectors
	double GetX(); // Access the x value
	double GetY(); // Access the y value
	// Modifiers
	void SetX(double newxval); // Set the x value
	void SetY(double newyval); // Set the y value
	//To String Method for describing the point
	string ToString();
};
#endif
 