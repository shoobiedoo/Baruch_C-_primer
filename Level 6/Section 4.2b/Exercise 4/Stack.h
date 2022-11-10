#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Array.h"
using namespace std;
//defining the template name as type T
template <typename T>
class Stack
{
private:
	Array <T> arr;
	int m_current;
public:
	Stack();//default constructor
	Stack(int size);//parametrized size constructor
	Stack(const Stack& a);// copy constructor
	virtual ~Stack();//destructor declared cirtual so even the derived class destructor is called
	int CurrentIndex() const;//returns the current index of the stack
	T Pop();//Pop cant be const as we are changin m_index
	void Push(T& source);//Push
	Stack& operator = (const Stack& a);//canonical assignment operator
};
#ifndef STACK_CPP // Same as in the source file 
#include "Stack.cpp"
#endif
#endif