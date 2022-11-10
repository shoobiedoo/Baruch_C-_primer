// point.cpp
#include "point.h"
#include <sstream>
#include <string>
Point::Point()
{//Default constructor
	x = y = 0.0;
	cout<<"Point created using default constructor"<<endl;
}

Point::Point(double newx, double newy)// Parameterized constructor
{// Initialize using newx and newy
	x = newx;
	y = newy;
}
Point::~Point()
{// Destructor
	cout << "Point destroyed"<<endl;//Display message of the destructor for checking the overall functionality of the point destructor
}
//Access the x value
double Point::GetX()
{
	return x;
}
// Access the y value
double Point::GetY()
{
	return y;
}
// Modifiers
// Set the x value 
void Point::SetX(double newxval)
{
	//assigning x with the given x value 
	x = newxval;
}
// Set the y value
void Point::SetY(double newyval)
{
	//assigning y with the given y value
	y = newyval;
}
//To string method for printing the description of the point itself
string Point::ToString() {
	ostringstream temp;//defining the output string stream
	temp<<"Point("<<x<<","<<y<<")"<<endl;//returning the description about the point's coordinates
	return temp.str();//using the .str() method to get the string out of the outpout string stream
}