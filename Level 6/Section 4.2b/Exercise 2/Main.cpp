#include "NumericArray.h"//we can keep including NumericArray.h if we add the source file def explicitly inside Array.h
#include <iostream>
#include "OutOfBoundsException.h"
#include "ArrayException.h"
#include "Point.h"
using namespace std;
int main() {
	try {
		/*
		* Regarding the assumption for the type for numeric arrays it should be only a type which supports all 3
		* operators of *(scalar) + and dotProduct which has *(T&) internally*/
		//default size declared is 11
		int size;
		cout << "Integer numeric array " << endl;
		cout << "Please enter the size of array 1 : " << endl;
		cin >> size;
		NumericArray<int> intArray1(size);
		cout << "Please enter the numbers";
		for (int i = 0; i < size; i++) {
			cin >> intArray1[i];
			cout << intArray1[i] << endl;
		}
		cout << "Please enter the size of array 2 : " << endl;
		cin >> size;
		NumericArray<int> intArray2(size);
		for (int i = 0; i < size; i++) {
			cin >> intArray2[i];
			cout << intArray2[i] << endl;
		}
		
		cout << "Adding array 1 and 2"<< endl;
		NumericArray<int> intArray3 = intArray1 + intArray2;
		for (int i = 0; i < intArray3.Size(); i++) {
			cout << intArray3[i]<<endl;
		}

		cout << "Scaling the previous array sum by 2" << endl;
		NumericArray<int> intArray4 = intArray3 * 2;
		for (int i = 0; i < intArray3.Size(); i++) {
			cout << intArray4[i] << endl;
		}

		cout << "Dot Product of array 1 and 2 : " << intArray1.DotProduct(intArray2)<<endl;
		cout << "Point numeric array" << endl;
		cout << "Please enter the size of point array 1 : " << endl;
		cin >> size;
		NumericArray<Point> pointArray1(size);
		cout << "Please enter the x and y"<<endl;
		for (int i = 0; i < size; i++) {
			double x;
			double y;
			cin >> x>> y;
			pointArray1[i] = Point(x, y);
			cout << pointArray1[i] << endl;
		}
		cout << "Please enter the size of point array 2 : " << endl;
		cin >> size;
		NumericArray<Point> pointArray2(size);
		cout << "Please enter x and y for the points"<<endl;
		for (int i = 0; i < size; i++) {
			double x;
			double y;
			cin >> x >> y;
			pointArray2[i] = Point(x, y);
			cout << pointArray2[i] << endl;
		}

		cout << "Adding point array 1 and 2" << endl;
		NumericArray<Point> pointArray3 = pointArray1 + pointArray2;
		for (int i = 0; i < pointArray3.Size(); i++) {
			cout << pointArray3[i] << endl;
		}

		cout << "Scaling the previous point array sum by 2" << endl;
		NumericArray<Point> pointArray4 = pointArray3 * 2;
		for (int i = 0; i < pointArray3.Size(); i++) {
			cout << pointArray4[i] << endl;
		}

	/* This wont work for point array because there is no operator avaialbe for this operation in Points which is of the kind Point * Point
		cout << "Dot Product of array 1 and 2 : " << pointArray1.DotProduct(pointArray2) << endl;
		*/
	}
	catch (ArraySizeMismatchException& e) {
		cout << "Main Exception " << e.GetMessage();
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