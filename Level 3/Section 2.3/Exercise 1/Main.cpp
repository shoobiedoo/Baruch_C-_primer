// Test program for the point class.
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
	cout << "The x coordinate of point 1 using getX function is " << pt.GetX() << endl;//Printing the x coordinate using the GETX function to check the overall functionality
	cout << "The y coordinate of point 1 using getY function is " << pt.GetY() << endl;//Printing the y coordinate using the GETY function to check the overall functionality
	cout << pt.ToString();//printing out the point description using the ToString method

	Point ptCopy(pt);//copying the point to self
	cout << "The copy point is "<<ptCopy.ToString() << endl;
	cout << "The distance of point 1 from copy point is " << pt.Distance(ptCopy) << endl;//Priting the distance of point 1 from point 2
	/* without the explicit copy constructor because the distance method is call by value ; 
		the destructor message is displayed one more time than the corresponding numbers of constructors because
		the default copy constructor does not have a display message
		however for the newly defined copy constructor ; we can see the corresponding constructor and destructor messages
	*/
	cout << "Please enter the x and y coordinates for the second point"<<endl;
	cin >> x >> y;//Taking user input for x and y for the second point

	Point p2(x, y);
	cout << endl;
	cout << "The distance of point 1 from origin is " << pt.DistanceOrigin() << endl;//Printing the distance of point 1 from origin 
	cout << "The distance of point 1 from point 2 is " << pt.Distance(p2) << endl;//Priting the distance of point 1 from point 2
	return 0;
}

