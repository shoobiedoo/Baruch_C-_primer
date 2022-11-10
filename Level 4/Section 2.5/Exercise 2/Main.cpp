// Test program for the point class 
#include <iostream>
#include "point.h"
#define ll long long int
int main()
{
	Point* tempPoint = new Point(3, 4);// temp point which will be used 
	Point** pArray = new Point * [3];// declaring an array of pointers
	pArray[0] = new Point();//point created using default constructor
	pArray[1] = new Point(1, 2);//point created using parameterized constructor
	pArray[2] = new Point(*tempPoint);//point created using copy constructor
	for (int i = 0; i < 3; i++) {
		cout << *pArray[i] << endl;//displays the point stored in each pointer
	}
	for (int i = 0; i < 3; i++) {
		delete pArray[i] ;//deleting every point inside the array
	}
	delete[] pArray;//deleting the array and freeing the individual points
	delete tempPoint;//deleting the temp variable used for creating a point using the copy constructor
	/*
	
	Memory layout of the program :
	heap memory addresses pointed by pArray: [A] [B] [C]
	heap memory address pointed by [A] stores Object 1
	heap memory address pointed by [B] stores Object 2
	heap memory address pointed by [C] stores Object 3	
	*/
	return 0;
}