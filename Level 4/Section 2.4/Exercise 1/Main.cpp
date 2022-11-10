// Test program for the operator overloading done across all point line and circle classes
#include <iostream>
#include "point.h"
#include "line.h"
#include "circle.h"
int main()
{
	double x1, y1, x2, y2;//Declaring the input variables for storing the user input
	cout << "Please enter the x and y coordinates for the first point\n";
	cin >> x1 >> y1;//Taking user input for x and y for the first point
	cout << "Please enter the x and y coordinates for the second point" << endl;
	cin >> x2 >> y2;//Taking user input for x and y for the second point

	//Point arithmetic;

	Point p1 = Point(x1, y1);
	Point p2 = Point(x2, y2);
	Point p3;
	//checking the unary - operator
	cout << "Pre negation the point p1 is " << p1.ToString() << endl;
	cout << "Post negation the point p1 is " << (-p1).ToString() << endl;
	// checking the *(double) operator
	cout << "Pre scaling the point p2 is " << p2.ToString() << endl;
	cout << "Post scaling the point p2 is " << (p2 * 2).ToString() << endl;
	//checking the assignment operator
	p3 = p1;
	cout << "Post assignment point p3 is " << p3.ToString() << endl;
	//checking the equality operator
	cout << "Point p3 is" << ((p3 == p1)?" equal to p1" : " not equal to p1") << endl;
	cout << "Point p3 is"<< ((p3 == p2) ?" equal to p2" : " not equal to p2" )<< endl;
	//checking the *= operator
	cout << "Pre updating the point p2 is " << p2.ToString() << endl;
	p2 *= 2;
	cout << "Post updating the point p2 is " << (p2).ToString() << endl;
	//checking the binary + operator
	cout << "Pre adding the updated points p1 and p2 are " << p1.ToString() << " " << p2.ToString() << endl;
	Point p4 = p1 + p2;
	cout << "Post adding the point p4 which indicates the their sum is " << (p4).ToString() << endl;

	Line l(p1,p2);//Declaring the line with given starting and ending point 
	cout << "The starting point of line using the getter start() is " << l.start().ToString() << endl;
	cout << "The ending point of line using the getter end() is " << l.end().ToString() << endl;
	cout << "The description of the line : " << l.ToString() << endl;//displaying the description of the line
	cout << "The length of the line is " << l.Length() << endl;//displaying the length of the line
	cout << "Self assigning line" << endl;
	l = l;//checking whether self assignment is avoided or not
	Line l2(p3, p4);//Declaring a second line to show how assignment overrides the existing parameters
	cout << "The description of the line L2: " << l2.ToString() << endl;
	l2 = l;//checking the canonical assignment operator
	cout << "Assigning l2 = l ; now L2 is " << l2.ToString() << endl;



	double x, y, radius;//Declaring the input variables for storing the user input
	cout << "Please enter the x and y coordinates for the center point\n";
	cin >> x >> y;//Taking user input for x and y for the first point
	cout << "Please enter the radius of the circle" << endl;
	cin >> radius;//Taking user input for x and y for the second point
	Circle c(radius, Point(x, y));//Declaring the Circle with given starting and ending point 
	cout << "The center point of Circle using the getter centerPoint() is " << c.centerPoint().ToString() << endl;
	cout << "The radius of Circle using the getter Radius() is " << c.Radius() << endl;
	cout << "The description of the Circle : " << c.ToString() << endl;//displaying the description of the Circle
	cout << "The diameter of the Circle is " << c.Diameter() << endl;//displaying the diameter of the Circle
	cout << "The circumference of the Circle is " << c.Circumference() << endl;//displaying the diameter of the Circle
	cout << "The area of the Circle is " << c.Area() << endl;//displaying the diameter of the Circle
	cout << "Self assigning circle" << endl;
	c = c;//checking whether self assignment is avoided or not
	Circle c2(radius/2, p4);//Declaring a second circle to show how assignment overrides the existing parameters
	cout << "The description of the circle C2: " << c2.ToString() << endl;
	c2 = c;//checking the assignment operator
	cout << "Assigning C2 = C ; now C2 is " << c2.ToString() << endl;


	return 0;
}