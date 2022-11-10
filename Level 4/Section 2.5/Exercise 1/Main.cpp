// Test program for the point class.
#include <iostream>
#include "point.h"
#define ll long long int
int main()
{
	/*
	Removed ToString() method in the cout statement wherever we were displaying the description
	of the circle line or point and declaring it as a friend to all the other classes so that we can directly access all the private members while printing
	*/

	double x1, y1, x2, y2;//Declaring the input variables for storing the user input
	cout << "Please enter the x and y coordinates for the first point\n";
	cin >> x1 >> y1;//Taking user input for x and y for the first point
	cout << "Please enter the x and y coordinates for the second point" << endl;
	cin >> x2 >> y2;//Taking user input for x and y for the second point

	//Point arithmetic;

	Point * p1 = new Point(); // point being created on heap using default constr.
	p1->X(x1);
	p1->Y(y1);
	Point * p2 =new Point(x2, y2); // point being created on heap using parametrized constr.
	Point * p3 = new Point(*p1);//using copy constr
	cout << "The point p1 created using the default constructor : " << *p1 << endl;
	cout << "The point p2 created using default constructor : " << *p2 << endl;
	cout << "The point p3 containing p1 as a copy using the copy constructor : " << *p3 << endl;
	cout << "The distance between point p1 and p2 is : " << p1->Distance(*p2) << endl;
	cout << "The point p1 pointer/address is " << p1 << endl;
	cout << "The actual point p1 is " << *p1 << endl;
	delete p1;
	delete p2;
	delete p3;


	cout << "Please enter the array size : " << endl;
	ll n; // user input of array size : n
	cin >> n;
	// Point pArray[n]; Array Creation on stack  Throws error as the compiler requires the size of array for mem allocation
	Point * pArray = new Point[n];//creating an array of points on heap of size n using the default constructor
	/*
	It is NOT possible to specify a different constructor to be called on creation. The default constructor is called 
	always.
	Something like this 	Point* pArray = new  Point(1.0)[n]; is bound to throw errors
	*/
	delete[] pArray;//deleting the array and freeing the individual points
	return 0;
}