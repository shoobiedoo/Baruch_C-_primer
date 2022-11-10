#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Shape.h"
int main() {
	/*
	* shape[i] = new Shape; will now throw error as Shape is an abstract class
	* 
	*/
	Shape* shapes[6];
	//Default constructor
	shapes[0] = new Line;
	shapes[1] = new Point;
	shapes[2] = new Circle;
	//Param constructor
	shapes[3] = new Point(1, 2);
	shapes[4] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));
	shapes[5] = new Circle(5,Point(1,1));
	cout << endl;
	cout << "drawing shapes now" << endl;
	for (int i = 0; i != 6; i++) shapes[i]->Draw();//drawing all the given shapes
	cout << endl;
	cout << "deleting the shapes now" << endl;
	for (int i = 0; i != 6; i++) delete shapes[i];//deleting the shapes
	return 0;
}