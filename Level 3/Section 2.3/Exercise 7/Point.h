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
	double X(); // Access the x value
	double Y(); // Access the y value
	// Modifiers
	// Default inline setter which sets the x value 
	void X(double newxval)//overloaded X function as setter
	{
		x = newxval;
	}
	// Default inline setter for Y value
	void Y(double newyval)//overloaded Y function as setter
	{
		y = newyval;
	}
	//To String Method
	string ToString();
	double Distance();//Function to find the distance of the current point from origin 
	double Distance(const Point& pt);// Function to find the distance of the current point from point one to point two
};
//normal inline getter for X
inline double Point::X()
{
	return x;
}
// normal inline getter for Y
inline double Point::Y()
{
	return y;
}
#endif
