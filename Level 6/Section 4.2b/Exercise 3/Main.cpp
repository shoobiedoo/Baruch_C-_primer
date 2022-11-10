#include "PointArray.h"//we can keep including array.h if we add the source file def explicitly inside Array.h
#include <iostream>
#include "OutOfBoundsException.h"
#include "ArrayException.h"
#include "Point.h"
using namespace std;
int main() {
	try {
		/*
		* Regarding the assumption for the type for point arrays it should be only a type which supports all 3
		* operators of *(scalar) + and dotProduct which has *(T&) internally*/
		//default size declared is 11
		/*
		PointArray<int> intArray1(size); this will throw an error because of concrete inheritance
		*/
		int size;
		cout << "Point numeric array" << endl;
		cout << "Please enter the size of point array 1 : " << endl;
		cin >> size;
		PointArray pointArray1(size);//creating a point array of given size
		cout << "Please enter the x and y" << endl;
		for (int i = 0; i < size; i++) {
			double x;
			double y;
			cin >> x >> y;
			pointArray1[i] = Point(x, y);
			cout << pointArray1[i] << endl;//printing the points in the array 
		}
		cout << "The length of pointArray1 is " << pointArray1.Length() << endl;//printing the length of all the points in the point array
		Point temp1 = Point(-1, -1);
		Point temp2 = Point(2, 2.2);
		PointArray pointArray2(2);
		pointArray2.SetElement(0,temp1);
		pointArray2.SetElement(1,temp2);
		cout << "Printing pointArray 2 : " << endl;
		for (int i = 0; i < pointArray2.Size(); i++) {
			cout << pointArray2.GetElement(i) << " ";
		}
		//assigning pointarray 2 to 1
		pointArray1 = pointArray2;
		cout << "Printing pointArray 1 : " << endl;
		for (int i = 0; i < pointArray1.Size(); i++) {
			cout << pointArray1[i] << " " << endl;
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