// Test program for the point class with additional functionality of distance from origin and another given point
#include <iostream>
#include "point.h"
int main()
{
	double x, y;//Declaring the input variables x and y for storing the user input
	cout << "Please enter the x and y coordinates for the first point\n";
	cin >> x >> y;//Taking user input for x and y for the first point
	cout << endl;
	Point pt;//Creating the first point using the default instructor
	pt.SetX(x);//setting the user entered x value using the SETX method
	pt.SetY(y);//setting the user entered y value using the SETY method
	cout << pt.ToString();//printing out the point description using the ToString method

	cout << "Please enter the x and y coordinates for the second point\n";
	cin >> x >> y;//Taking user input for x and y for the second point
	Point p2(x,y);//declaring the second point using parametrized constructor
	cout << endl;
	cout << "The x coordinate of point 1 using getX function is " << pt.GetX() << endl;//Printing the x coordinate using the GETX function to check the overall functionality
	cout << "The y coordinate of point 1 using getY function is " << pt.GetY() << endl;//Printing the y coordinate using the GETY function to check the overall functionality
	cout << "The distance of point 1 from origin is " << pt.DistanceOrigin() << endl;//Printing the distance of point 1 from origin 
	cout << "The distance of point 1 from point 2 is " << pt.Distance(p2) << endl;//Priting the distance of point 1 from point 2
	return 0;
}
