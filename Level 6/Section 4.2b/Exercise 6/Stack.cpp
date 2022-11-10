
#ifndef STACK_CPP
#define STACK_CPP
#include "stack.h"
#include "point.h"
#include "OutOfBoundsException.h"
#include "ArrayException.h"
#include "StackException.h"
#include "StackEmptyException.h"
#include "StackFullException.h"

template <typename T,int size>
Stack<T,size>::Stack() :arr(Array<T>(size)), m_current(0) {
	//initializing the m_current with the default index in the default constructor alongwith the default array
	cout << "Default constructor is called to create stack of size : " << arr.Size() << endl;
}

template <typename T,int size>
Stack<T,size>::Stack(const Stack<T,size> & s) : arr(s.arr), m_current(s.m_current) {//copying the parameters
	cout << "We can only copy stacks of same size and type" << endl;
	cout << "Copy constructor is called to create an stack of size " << size << endl;
}
template <typename T,int size>
Stack<T,size>::~Stack() {
	cout << "Default destructor deleting stack of size " << arr.Size() << endl;
}
//assignment operator overloading as in the canonical header file
template <typename T,int size>
Stack<T,size>& Stack<T,size>::operator = (const Stack<T,size>& a)
{
	cout << "Assigning stack to new stack of size: " << a.arr.Size() << endl;

	// Avoid doing assign to myself
	if (this == &a) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}

	arr = a.arr;
	m_current = a.m_current;
	return *this;
}
template <typename T,int size>
int Stack<T,size>::CurrentIndex() const {
	//returns the index of the current available position in the stack
	//which means the last entered element in the stack will be at currIndex-1
	return m_current;
}

template <typename T,int size>
void Stack<T,size>::Push(T& source) {
	try {
		if (m_current >= arr.Size()) {  // not checking the bounds condition for exception handling ; only for the display message
			cout << "Stack overflow going to catch block now " << endl;
		}
		arr[m_current] = source; //assigning the current index to source 
		m_current++; // updating the index only after the array has accessed the element 
	}
	catch (OutOfBoundsException& e) {
		throw StackFullException(m_current);
	}
}
template <typename T,int size>
T Stack<T,size>::Pop() {
	try {
		if (m_current <= 0) {  // checking the bounds condition although there is no need as the array will throw an exception 
			cout << "Stack is empty already going to catch block now" << endl;
		}
		T temp = arr[m_current - 1];//if the index before the current available element's index is inaccessible ; throw an exception which will be done by the array
		m_current--;// updating the index only after the array has accessed the element 
		return temp;
	}
	catch (OutOfBoundsException& e) {
		throw StackEmptyException(m_current - 1);
		m_current = 0;//however it is already zero as we only update the current index if everything is working fine 
	}
}
#endif