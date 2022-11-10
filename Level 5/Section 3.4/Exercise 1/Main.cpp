#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Circle.h"
int main() {
	/*Testing the constructors using colon syntax
	and how we maintain separation of concerns by only initialising the primitive types inside the line object and all the
	members of the point object are only initialized within the point object itself;
	The number of times constructors change happens because the compiler will create startPoint and endPoint even before going to the
	line constructor and thus there is an additional layer of constructors and destructors being called alongwith assignment whenever 
	we dont use : syntax for the default constructor
	otherwise they remain the same 
	*/
	Line l;
	cout << "line 1 creation done" << endl;
	cout << l << endl;
	Line l2(Point(1, 2), Point(3, 4));
	cout << "line 2 creation done" << endl;
	cout << l2 << endl;
	
	Circle c;//same can be seen for circle object
	cout << "Circle 1 creation done " << endl;
	cout << c << endl;
	Circle c2(5,Point(1, 2));
	cout << "Circle 2 creation done" << endl;
	cout << c2 << endl;
	return 0;
}