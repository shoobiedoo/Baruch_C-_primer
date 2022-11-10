
#include "Stack.h"//we can keep including array.h if we add the source file def explicitly inside Array.h
#include <iostream>
#include "StackFullException.h"
#include "StackEmptyException.h"
#include "StackException.h"
#include "Point.h"
using namespace std;
int main() {
	try {
		//default size declared is 11
		Stack<Point, 2> pointStack1;
		Stack<Point, 2> pointStack2;

		Point temp = Point(1, 0);
		pointStack1.Push(temp);
		temp = Point(1, 2);
		pointStack1.Push(temp);

		temp = Point(3, 4);
		pointStack2.Push(temp);
		pointStack2 = pointStack1;
		cout << "Popping all stack 2 elements one by one after assigning it as stack 1"<<endl;
		while (pointStack2.CurrentIndex() != 0) {
			cout << pointStack2.Pop() << endl;
		}
		
		/* copying or assigning stacks of different size gives compiler error
		Stack<Point, 3> pointStack3;
		pointStack1 = pointStack3; //both these statements will result in an error
		Stack<Point, 4> pointStack4(pointStack3);// both these statements will result in an error
		*/

		/*
		Uncomment below to throw stack overflow exception
		*/
		/* if we run this piece of code we can actually see a stack overflow situation as we are trying to push more than the size of the stack
		Point temp = Point(0, 0);
		stack1.Push(temp);//throws StackFullException
		*/
		/*
		Uncomment below to throw stack underflow exception
		*/
		//stack1.Pop(); if i run this; it will actually throw an exception because stack is empty and we are still trying to pop an element 
		//throws StackEmptyException
		//checking whether template is working fine for doing the same as above for an int stack

		cout << "int Stack" << endl;
		Stack<int,2> stack2;//creating a int stack of given size 2
		int tempint = 1;
		stack2.Push(tempint);
		tempint = 2;
		stack2.Push(tempint);
		Stack<int, 2> stack3(stack2);//creating another stack with same size using copy constructor
		cout << "Popping out all stack 3 elemtns" << endl;
		while (stack3.CurrentIndex() != 0) {
			cout << stack3.Pop() << endl;
		}

	}
	catch (StackFullException& e) {
		cout << "Main Exception : stack overflow " << e.GetMessage();
	}
	catch (StackEmptyException& e) {
		cout << "Main Exception : stack underflow " << e.GetMessage();
	}
	catch (StackException& e) {
		cout << "Main Exception " << e.GetMessage() << "only" << endl;
	}
	catch (...) {
		cout << "Main Exception " << "Unknown Exception is thrown" << endl;
	}
	return 0;
}