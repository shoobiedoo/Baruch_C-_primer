#include "Array.h"//we can keep including array.h if we add the source file def explicitly inside Array.h
#include <iostream>
#include "OutOfBoundsException.h"
#include "ArrayException.h"
using namespace std;
int main() {
	try {
		//default size declared is 11
		Array<int> intArray1;
		Array<int> intArray2;
		Array<double> doubleArray;
		cout << intArray1.DefaultSize() << endl; // prints the initial default size 11
		cout << intArray2.DefaultSize() << endl; // prints the initial default size 11
		cout << doubleArray.DefaultSize() << endl;// prints the initial default size 11
		intArray1.DefaultSize(15); // sets the size of all the integer array classes to 15
		cout << intArray1.DefaultSize() << endl;// prints 15
		cout << intArray2.DefaultSize() << endl;//prints 15
		cout << doubleArray.DefaultSize() << endl;//prints 11 as doubleArray is a different class and static members belong to a class
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