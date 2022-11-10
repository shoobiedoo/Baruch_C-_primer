// Test program for the point class and printing all the point details using getters and description methods
#include <iostream>
#include "point.h"
int main()
{
	double x, y;//Declaring the input variables x and y for storing the user input
	cout << "Please enter the x and y coordinates\n";
	cin >> x >> y;//Taking user input for x and y
	Point pt;//Creating the point using the default instructor
	pt.SetX(x);//setting the user entered x value using the SetX method
	pt.SetY(y);//setting the user entered y value using the SetY method
	cout << pt.ToString();//printing out the point description using the ToString method
	cout << "The x coordinate using getX function is " << pt.GetX() << endl;//Printing the x coordinate using the GetX function to check the overall functionality
	cout << "The y coordinate using getY function is " << pt.GetY() << endl;//Printing the y coordinate using the GetY function to check the overall functionality
	return 0;
}
