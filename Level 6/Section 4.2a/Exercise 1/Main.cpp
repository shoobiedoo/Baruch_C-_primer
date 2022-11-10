#include "Array.h"//we can keep including array.h if we add the source file def explicitly inside Array.h
#include "Point.h"
#include "Line.h"
#include <iostream>
using namespace std;
int main(){
	try {
		cout << "Enter the size of the array a2 you want to create using the parametrized constructor" << endl;
		int size;
		cin >> size;
		Array<Point> points(size);
		cout << "enter the corresp. x and y coordinates for arr a2" << endl;
		for (int i = 0; i < size; i++) {
			double x, y;
			cin >> x >> y; //taking input for the x and y coordinates for the Array
			points[i] = Point(x, y);
			cout << "A2[" << i << "] = " << points[i] << endl;
		}
		Point temp = Point(1, 3);
		//one case can be where array size is 0 put not checking that case as a separate test and assuming it to be a part of out of bounds
		for (int i = 0; i < size; i++) {
			cout << "Testing GetElement" << endl;
			cout << "points[" << i << "] = " << points.GetElement(i) << endl;// getting index in range

			cout << "Testing SetElement" << endl;
			points.SetElement(i, temp);// setting index in range
			cout << "points[" << i << "] = " << points.GetElement(i) << endl;

			cout << "Testing [] operator for accessing" << endl;
			cout << "points[" << i << "] = " << points[i] << endl;// getting index index in range

			cout << "Testing [] operator for assigning" << endl;
			points[i] = temp * 2;// setting index in range
			cout << "points[" << i << "] = " << points[i] << endl;
		}
		cout << endl;
		Array <Line> lines(size-1);//creating a line array of two adjacent points in the points array
		for (int i = 0; i < size-1; i++) {
			lines[i] = Line(points[i + 1],points[1]);
			cout << lines[i] << endl;
		}

	}
	catch (OutOfBoundsException& e) {
		cout << "Main Exception" << e.GetMessage();
	}
	catch (ArrayException& e) {
		cout << "Main Exception" << e.GetMessage() << "only" << endl;
	}
	catch (...) {
		cout << "Main Exception" << "Unknown Exception is thrown" << endl;
	}
	return 0;
}