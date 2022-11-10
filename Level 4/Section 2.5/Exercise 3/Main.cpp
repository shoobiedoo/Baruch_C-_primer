// Test program for the Array class
#include <iostream>
#include "point.h"
#include "array.h"
#define ll long long int
int main()
{
	Array a1;
	cout << "The size of the array a1 constructed using the default constructor " << a1.Size() << endl;
	cout << "Enter the size of the array a2 you want to create using the parametrized constructor"<<endl;
	int size;
	cin >> size;
	Array a2(size);
	cout << "enter the corresp. x and y coordinates for arr a2" << endl;
	for (int i = 0; i < size; i++) {
		double x, y;
		cin >> x >> y; //taking input for the x and y coordinates for the Array
		a2[i] = Point(x,y);
		cout << "A2[" << i << "] = "<<a2[i] << endl;
	}
	Array a3(a1);//copying the array a1
	a3 = a2;//reassigning array a3 to a2 this will show deallocation on the console output
	for (int i = 0; i < size; i++) {
		cout << "A3[" << i << "] = " << a3[i] << endl;
	}
	for (int i = 0; i < size; i++) {
		cout << "A3[" << i << "] = " << a3.GetElement(i) << endl;
	}
	cout << "Checking what happens if we try accessing an element which goes out of bound" << endl;
	cout << "A3[" << size+1 << "] = " << a3.GetElement(size+1) << endl;
	Point temp = Point(-1, -1);
	//setting a3 to temp point to check how the setter works and reassigns by deallocation existing Point object
	a3.SetElement(0, temp);
	cout << "A3[" << 0 << "] = " << a3.GetElement(0) << endl;
	return 0;
}