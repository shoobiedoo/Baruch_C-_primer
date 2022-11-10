// Test program for the point class.
#include <iostream>
#include "point.h"
#include "line.h"

int main()
{
	/*
	Removed ToString() method in the cout statement wherever we were displaying the description
	of the circle line or point and declaring it as a friend to all the other classes so that we can directly access all the private members while printing 
	and now the << operator can also access the private members of the point and line classes
	*/

	double x1, y1, x2, y2;//Declaring the input variables for storing the user input
	cout << "Please enter the x and y coordinates for the first point\n";
	cin >> x1 >> y1;//Taking user input for x and y for the first point
	cout << "Please enter the x and y coordinates for the second point" << endl;
	cin >> x2 >> y2;//Taking user input for x and y for the second point

	//Point arithmetic;

	Point p1 = Point(x1, y1);
	Point p2 = Point(x2, y2);
	Point p3;
	// checking whether the << operator can access the internal member methods 
	//checking the unary - operator
	cout << "Pre negation the point p1 is " << p1 << endl;
	cout << "Post negation the point p1 is " << (-p1) << endl;
	// checking the *(double) operator
	cout << "Pre scaling the point p2 is " << p2 << endl;
	cout << "Post scaling the point p2 is " << (p2 * 2) << endl;
	//checking the assignment operator
	p3 = p1;
	cout << "Post assignment point p3 is " << p3 << endl;
	//checking the equality operator
	cout << "Point p3 is" << ((p3 == p1) ? " equal to p1" : " not equal to p1") << endl;
	cout << "Point p3 is" << ((p3 == p2) ? " equal to p2" : " not equal to p2") << endl;
	//checking the *= operator
	cout << "Pre updating the point p2 is " << p2 << endl;
	p2 *= 2;
	cout << "Post updating the point p2 is " << (p2) << endl;
	//checking the binary + operator
	cout << "Pre adding the updated points p1 and p2 are " << p1 << " " << p2 << endl;
	Point p4 = p1 + p2;
	cout << "Post adding the point p4 which indicates the their sum is " << (p4) << endl;

	Line l(p1, p2);//Declaring the line with given starting and ending point 
	cout << "The starting point of line using the getter start() is " << l.start() << endl;
	cout << "The ending point of line using the getter end() is " << l.end() << endl;
	cout << "The description of the line : " << l << endl;//displaying the description of the line
	cout << "The length of the line is " << l.Length() << endl;//displaying the length of the line
	cout << "Self assigning line" << endl;
	l = l;//checking whether self assignment is avoided or not
	Line l2(p3, p4);//Declaring a second line to show how assignment overrides the existing parameters
	cout << "The description of the line L2: " << l2 << endl;
	l2 = l;//checking the canonical assignment operator
	cout << "Assigning l2 = l ; now L2 is " << l2 << endl;

	return 0;
}