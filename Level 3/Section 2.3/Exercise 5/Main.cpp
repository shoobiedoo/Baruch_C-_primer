// Test program for the line and point class .
#include <iostream>
#include "point.h"
#include "line.h"
int main()
{
	double x1, y1, x2, y2;//Declaring the input variables for storing the user input
	cout << "Please enter the x and y coordinates for the starting point\n";
	cin >> x1 >> y1;//Taking user input for x and y for the first point
	cout << "Please enter the x and y coordinates for the second point" << endl;
	cin >> x2 >> y2;//Taking user input for x and y for the second point
	Line l(Point(x1,y1), Point(x2,y2));//Declaring the line with given starting and ending point 
	cout << "The starting point of line using the getter start() is " << l.start().ToString() << endl;
	cout << "The ending point of line using the getter end() is " << l.end().ToString() << endl;
	cout << "The description of the line : " << l.ToString() << endl;//displaying the description of the line
	cout << "The length of the line is " << l.Length() << endl;//displaying the length of the line
	return 0;
}