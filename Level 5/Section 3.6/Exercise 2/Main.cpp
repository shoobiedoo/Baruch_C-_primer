// Test program for the Array class
#include <iostream>
#include "point.h"
#include "array.h"
#include "outofboundsexception.h"
#include "arrayexception.h"
#define ll long long int
int main()
{
	try {
		cout << "Enter the size of the array a2 you want to create using the parametrized constructor" << endl;
		int size;
		cin >> size;
		Array a2(size);
		cout << "enter the corresp. x and y coordinates for arr a2" << endl;
		for (int i = 0; i < size; i++) {
			double x, y;
			cin >> x >> y; //taking input for the x and y coordinates for the Array
			a2[i] = Point(x, y);
			cout << "A2[" << i << "] = " << a2[i] << endl;
		}
		Point temp = Point(1, 3);
		//one case can be where array size is 0 put not checking that case as a separate test and assuming it to be a part of out of bounds
		cout << "Testing GetElement" << endl;
		cout << "A2[" << 0 << "] = " << a2.GetElement(0) << endl;// getting index in range
		cout << "A2[" << -3 << "] = " << a2.GetElement(-3) << endl;//getting index < 0
		cout << "A2[" << size + 2 << "] = " << a2.GetElement(size + 2) << endl;// getting index > size

		cout << "Testing SetElement" << endl;
		a2.SetElement(0, temp);// setting index in range
		cout << "A2[" << 0 << "] = " << a2.GetElement(0) << endl;
		a2.SetElement(-3, temp);// setting index < 0
		cout << "A2[" << -3 << "] = " << a2.GetElement(-3) << endl;
		a2.SetElement(size + 2, temp);//setting index > size
		cout << "A2[" << size + 2 << "] = " << a2.GetElement(size + 2) << endl;

		cout << "Testing [] operator for accessing" << endl;
		cout << "A2[" << 0 << "] = " << a2[0] << endl;// getting index index in range
		cout << "A2[" << -3 << "] = " << a2[-3] << endl;// getting index < 0
		cout << "A2[" << size + 2 << "] = " << a2[size + 2] << endl;//  getting index > size

		cout << "Testing [] operator for assigning" << endl;
		a2[0] = temp;// setting index in range
		cout << "A2[" << 0 << "] = " << a2[0] << endl;
		a2[-3] = temp;// setting index < 0
		cout << "A2[" << -3 << "] = " << a2[-3] << endl;
		a2[size + 2] = temp;// setting index > size
		cout << "A2[" << size + 2 << "] = " << a2[size + 2] << endl;
	}
	catch (OutOfBoundsException& e) {
			cout <<"Main Exception"<< e.GetMessage();
	}
	catch (ArrayException& e) {
		cout << "Main Exception" << e.GetMessage() << "only"<<endl;
	}
	catch (...) {
		cout << "Main Exception" << "Unknown Exception is thrown" << endl;
	}
	return 0;
}