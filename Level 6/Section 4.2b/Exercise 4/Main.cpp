#include "Stack.h"//we can keep including stack.h if we add the source file def explicitly inside Array.h
#include <iostream>
#include "OutOfBoundsException.h"
#include "ArrayException.h"
#include "Point.h"
using namespace std;
int main() {
	try {
		//default size declared is 11
		int size;
		cout << "Point Stack" << endl;
		cout << "Please enter the size of point stack : " << endl;
		cin >> size;
		Stack<Point> stack1(size);//creating a point stack of given size
		cout << "Please enter the x and y" << endl;
		for (int i = 0; i < size; i++) {
			double x;
			double y;
			cin >> x >> y;
			Point temp = Point(x, y);
			stack1.Push(temp);//pushing to the stack
		}

		Stack<Point> pointStack1(stack1);
		cout << "Copying the given point stack to another stack called pointstack using the copy constructor" << endl;
		cout << "Popping all copied point stack elements one by one " << endl;
		while (pointStack1.CurrentIndex() != 0) {
			cout << pointStack1.Pop() << endl;
		}
		/* if we run this piece of code we can actually see a stack overflow situation as we are trying to push more than the size of the stack
		Point temp = Point(0, 0);
		stack1.Push(temp);
		*/

		cout << "Popping all given point stack elements one by one "<<endl;
		while (stack1.CurrentIndex()!=0) {
			cout << stack1.Pop() << endl;
		}
		//stack1.Pop(); if i run this; it will actually throw an exception because stack is empty and we are still trying to pop an element 
	
		//checking whether template is working fine for doing the same as above for an int stack
	
		cout << "int Stack" << endl;
		cout << "Please enter the size of int stack : " << endl;
		cin >> size;
		Stack<int> stack2(size);//creating a int stack of given size
		cout << "Please enter the numbers" << endl;
		for (int i = 0; i < size; i++) {
			int x;
			cin >> x;
			stack2.Push(x);//pushing to the stack
		}

		Stack<int> intStack1=stack2;
		cout << "Copying the given int stack to another stack called intstack using the assignment operator" << endl;
		cout << "Popping all copied int stack elements one by one "<<endl;
		while (intStack1.CurrentIndex() != 0) {
			cout << intStack1.Pop() << endl;
		}

		cout << "Popping all given int stack elements one by one "<<endl;
		while (stack2.CurrentIndex() != 0) {
			cout << stack2.Pop() << endl;
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