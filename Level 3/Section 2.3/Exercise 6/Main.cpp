// Test program for the circle class to display all the necessary attributes and take user input
#include <iostream>
#include "point.h"
#include "circle.h"
int main()
{
	double x, y, radius;//Declaring the input variables for storing the user input
	cout << "Please enter the x and y coordinates for the center point\n";
	cin >> x >> y;//Taking user input for x and y for the first point
	cout << "Please enter the radius of the circle" << endl;
	cin >> radius;//Taking user input for x and y for the second point
	Circle c(radius,Point(x, y));//Declaring the Circle with given starting and ending point 
	cout << "The center point of Circle using the getter centerPoint() is " << c.centerPoint().ToString() << endl;
	cout << "The radius of Circle using the getter Radius() is " << c.Radius() << endl;
	cout << "The description of the Circle : " << c.ToString() << endl;//displaying the description of the Circle
	cout << "The diameter of the Circle is " << c.Diameter() << endl;//displaying the diameter of the Circle
	cout << "The circumference of the Circle is " << c.Circumference() << endl;//displaying the diameter of the Circle
	cout << "The area of the Circle is " << c.Area() << endl;//displaying the diameter of the Circle
	return 0;
}