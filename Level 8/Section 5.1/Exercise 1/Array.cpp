#include "Array.h"

#ifndef Array_CPP
#define Array_CPP
#include "array.h"
#include "point.h"
#include "OutOfBoundsException.h"
#include "ArrayException.h"
template <typename T>
int Array<T>::defaultSize = 11;//initializing the static variable inside the source file 

template <typename T>
Array<T>::Array() {
	//initializing the m_size with the default size in the default constructor
	m_data = new T[Array<T>::defaultSize];
	size = Array<T>::defaultSize;
	cout << "Default constructor is called to create array of size : " << size << endl;
}
template <typename T>
Array<T>::Array(int sz) {
	cout << "size constructor creating an array of size: " << sz << endl;
	m_data = new T[sz];
	size = sz;
}
template <typename T>
Array<T>::Array(const Array<T>& a) {
	cout << "Copy constructor is called to create an array of size " << a.size << endl;
	size = a.size;
	m_data = new T[size];
	for (int i = 0; i < size; i++) {
		m_data[i] = a.m_data[i];
	}
}
template <typename T>
Array<T>::~Array() {
	delete[] m_data;
	cout << "Default destructor deleting array of size: " << size << endl;
}
//assignment operator overloading as in the canonical header file
template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& a)
{
	cout << "Assigning array to new Array of size: " << a.Size() << endl;

	// Avoid doing assign to myself
	if (this == &a) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}
	cout << "Before assigning deleting the existing array of size " << size << endl;
	delete[] m_data;
	size = a.size;
	m_data = new T[size];
	for (int i = 0; i < size; i++) {
		m_data[i] = a.m_data[i];
	}
	return *this;
}
template <typename T>
int Array<T>::Size() const {
	return size;
}

template <typename T>
void Array<T>::DefaultSize(int newval)
{
	Array<T>::defaultSize = newval;//setting the static member defaultSize
}

template <typename T>
int Array<T>::DefaultSize()
{
	return Array<T>::defaultSize;//returning the static member defaultSize
}

// [] operator to just get the value at the particular index of the array
template <typename T>
const T& Array<T>::operator [] (int index) const {
	if (index < size && index >= 0) {  // checking the bounds condition
		return m_data[index];
	}
	else {
		throw OutOfBoundsException(index); // throwing OutOfBoundsException
	}
}
// to assign to the particular array index location
template <typename T>
T& Array<T>::operator [] (int index) {
	if (index < size && index >= 0) { // checking the bounds condition
		return m_data[index];
	}
	else {
		throw OutOfBoundsException(index);//throwing OutOfBoundsException
	}
}
template <typename T>
void Array<T>::SetElement(const int index, T& source) {
	if (index < size && index >= 0) {  // checking the bounds condition
		m_data[index] = source;
	}
	else {
		throw OutOfBoundsException(index);//OutOfBoundsException
	}
}
template <typename T>
T& Array<T>::GetElement(const int index) const {

	if (index < size && index >= 0) {  // checking the bounds condition
		return m_data[index];
	}
	else {
		throw OutOfBoundsException(index);//throwing OutOfBoundsException
	}
}
#endif