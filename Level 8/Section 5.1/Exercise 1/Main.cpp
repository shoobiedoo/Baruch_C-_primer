/*
* Program to show how smart pointers especially shared pointers work and manage object deletion automatically instead of us clearing
* heap memory manually
*/
#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Shape.h"
#include "Array.h"
#include "boost/shared_ptr.hpp"
typedef shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;
int main() {
	//Declaring arrya of ShapePtr which is a shared_ptr so that deletion of shapes is taken care of automatically 
	Array<ShapePtr> shapes = Array< ShapePtr >(6);
	//Default constructor
	shapes[0] = ShapePtr(new Line);
	shapes[1] = ShapePtr(new Point);
	shapes[2] = ShapePtr(new Circle);
	//Param constructor
	shapes[3] = ShapePtr(new Point(1, 2));
	shapes[4] = ShapePtr(new Line(Point(1.0, 2.5), Point(3.4, 5.2)));
	shapes[5] = ShapePtr(new Circle(5, Point(1, 1)));
	cout << endl;
	cout << "Printing shapes now" << endl;
	for (int i = 0; i != 6; i++) {
		cout << endl;
		shapes[i]->Print();//Printing all the given shapes
	}
	cout << endl;
	//for (int i = 0; i != 6; i++) delete shapes[i];//no need for deleting the shapes as the shared pointer will automatically take care of it
	//the same can be seen as the default destructor will be called in the output console for each of the shapes 
	return 0;
}