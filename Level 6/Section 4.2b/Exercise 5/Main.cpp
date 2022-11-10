#include "Stack.h"//we can keep including Stack.h if we add the source file def explicitly inside Array.h
#include <iostream>
#include "StackFullException.h"
#include "StackEmptyException.h"
#include "StackException.h"
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
		/*
		Uncomment below to throw stack overflow exception
		*/
		/* if we run this piece of code we can actually see a stack overflow situation as we are trying to push more than the size of the stack
		Point temp = Point(0, 0);
		stack1.Push(temp);//throws StackFullException
		*/
		cout << "Creating another point stack by using copy constructor and copying stack 1" << endl;
		Stack<Point> pointStack2(stack1);//checking the copy constructor

		cout << "Popping all point stack one elements one by one ";
		while (stack1.CurrentIndex() != 0) {
			cout << stack1.Pop() << endl;
		}

		cout << "Popping all point stack two elements one by one ";
		while (pointStack2.CurrentIndex() != 0) {
			cout << pointStack2.Pop() << endl;
		}
		/*
		Uncomment below to throw stack underflow exception
		*/
		//stack1.Pop(); if i run this; it will actually throw an exception because stack is empty and we are still trying to pop an element 
		//throws StackEmptyException
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
		Stack<int> intStack2 = stack2; // checking the assignment operator before popping all int stack one elements
		cout << "Popping all int stack one elements one by one ";
		while (stack2.CurrentIndex() != 0) {
			cout << stack2.Pop() << endl;
		}
		
		cout << "Popping all int stack two elements one by one ";
		while (intStack2.CurrentIndex() != 0) {
			cout << intStack2.Pop() << endl;
		}
	}
	catch (StackFullException& e) {//catching the stack full exception
		cout << "Main Exception : stack overflow " << e.GetMessage();
	}
	catch (StackEmptyException& e) {//catching the stack empty exception
		cout << "Main Exception : stack underflow " << e.GetMessage();
	}
	catch (StackException& e) { // catching any other kind of Stack exception (Rn there is no other sub exception under stack)
		cout << "Main Exception " << e.GetMessage() << "only" << endl;
	}
	catch (...) {
		cout << "Main Exception " << "Unknown Exception is thrown" << endl;
	}
	return 0;
}