#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Shape.h"
int main() {
	Shape* shapes[3];
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;
	for (int i = 0; i != 3; i++) {
		cout << endl;// for better output formatting 
		delete shapes[i];
	}
	return 0;
}