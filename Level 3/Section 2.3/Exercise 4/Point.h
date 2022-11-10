// point.hpp
// Simple two dimensional point consisting of a x and y 
// value

#ifndef POINT_H
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
	Point(const Point& p);
	Point(double xval, double yval);
	~Point(); // Destructor
	//Selectors
	double X() const; // Access the x value
	double Y() const; // Access the y value
	// Modifiers
	void X(double newxval); // Set the x value
	void Y(double newyval); // Set the y value
	//To String Method
	string ToString() const;//declaring ToString function as constant so that the compiler knows this function will not update the point's value
	double Distance() const;//Function to find the distance of the current point from origin ; also declared as constant
	double Distance(const Point& pt) const;// Function to find the distance of the current point from point one to point two ; also declared as a constant 
};
#endif
