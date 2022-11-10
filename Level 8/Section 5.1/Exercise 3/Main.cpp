/*
* Main test program to check how variants work especially how they are type-safe
* and how variants also provided a logical grouping among different classes provided there is no Shape base class
*/
#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Shape.h"
#include "Visitor.h"
#include "boost/variant.hpp"
typedef boost::variant<Point, Line, Circle> ShapeType;//defining the variant
//Function to ask the user what kind of shape they want and returns the variant of the inputted shape
ShapeType CreateShape() {
	ShapeType ans;//defining the output variable to output the shape variant 
	cout << "Taking user input" << endl;
	cout << "Type 0 for point shape" << endl;
	cout << "Type 1 for line shape" << endl;
	cout << "Type 2 for circle shape" << endl;
	int shape;
	cin >> shape;
	//Switch case to assign the shape to the shape of user's choice
	switch (shape) {
	case 0:
		ans = Point(1, 2);
		break;
	case 1:
		ans = Line(Point(1, 2), Point(3, 4));
		break;
	case 2:
		ans = Circle(5, Point(1, 2));
		break;
	default:
		cout << "Wrong input fallthrough" << endl;
	}
	return ans;//returning the shape variant 
}
int main() {
	
	cout << CreateShape() << endl;//printing out the Function's return value 
	cout << endl;
	cout << "Checking the bad get case for Line variant : for not going to catch block select 1 for line " << endl;
	try {
		Line testLine = boost::get<Line>(CreateShape());// if the user create a differnt shape and we try using get for a differnt type
		//error is thrown
		cout << testLine;
	}
	catch (boost::bad_get) { //catching the bad_get exception because of the data type mismatch
		cout << "Catching bad get exception cause of invalid type" << endl;
	}

	//Create an instance of the visitor.
	Visitor vst(1, 2);
	cout << endl;
	cout << "Choosing the shape variant to use the variant on" << endl;
	ShapeType testShape = CreateShape();//creating a shape variant
	cout << endl;
	cout << "Printing the shape before applying the visitor offset" << endl;
	cout << testShape;//printing the shapes before using the visitor
	// Use the boost::apply_visitor(visitor, variant) global function to move the shape.
	boost::apply_visitor(vst, testShape);
	cout << "After visiting, shape is  = " << testShape << endl;
	return 0;
}