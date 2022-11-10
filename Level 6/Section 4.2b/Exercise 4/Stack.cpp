
#ifndef STACK_CPP
#define STACK_CPP
#include "stack.h"
#include "point.h"
#include "OutOfBoundsException.h"
#include "ArrayException.h"

template <typename T>
Stack<T>::Stack() :arr(Array<T>()), m_current(0) {
	//initializing the m_current with the default index in the default constructor alongwith the default array
	cout << "Default constructor is called to create stack of size : " << arr.Size() << endl;
}
template <typename T>
Stack<T>::Stack(int sz) : arr(Array<T>(sz)),m_current(0) {
	// inits the array to an array of size sz
	cout << "size constructor creating an stack of size: " << sz << endl;
}
template <typename T>
Stack<T>::Stack(const Stack<T>& s): arr(s.arr),m_current(s.m_current) {//copying the parameters
	cout << "Copy constructor is called to create an stack of size " << s.arr.Size() << endl;
}
template <typename T>
Stack<T>::~Stack() {
	cout << "Default destructor deleting stack" << arr.Size() << endl;
}
//assignment operator overloading as in the canonical header file
template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& a)
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
template <typename T>
int Stack<T>::CurrentIndex() const {
	//returns the index of the current available position in the stack
	//which means the last entered element in the stack will be at currIndex-1
	return m_current;
}

template <typename T>
void Stack<T>::Push(T& source) {
	if (m_current >= arr.Size()) {  // not checking the bounds condition for exception handling ; only for the display message
		cout << "Stack overflow " << endl;
	}
	arr[m_current] = source; //assigning the current index to source 
	m_current++; // updating the index only after the array has accessed the element 
}
template <typename T>
T Stack<T>::Pop() {
	if (m_current <= 0) {  // checking the bounds condition although there is no need as the array will throw an exception 
		cout << "Stack is empty already" << endl;
	}
	T temp = arr[m_current-1];//if the index before the current available element's index is inaccessible ; throw an exception which will be done by the array
	m_current--;// updating the index only after the array has accessed the element 
	return temp;
}
#endif