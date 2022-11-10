
#ifndef Array_CPP
#define Array_CPP
#include "array.h"
#include "OutOfBoundsException.h"
#include "ArrayException.h"

template <typename T>
Array<T>::Array() {
	cout << "Default constructor is called" << endl;
	m_data = new T[10];
	size = 10;
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
// [] operator to just get the value at the particular index of the array
template <typename T>
const T& Array<T>::operator [] (int index) const {
	// we declare an internal try catch so that we can differentiate between which method is throwing the OutOFBounds
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
	// we declare an internal try catch so that we can differentiate between which method is throwing the OutOfBounds
	if (index < size && index >= 0) { // checking the bounds condition
		return m_data[index];
	}
	else {
		throw OutOfBoundsException(index);//throwing OutOfBoundsException
	}
}
template <typename T>
void Array<T>::SetElement(const int index, T& source) {
	// we declare an internal try catch so that we can differentiate between which method is throwing the OutOfbounds
	if (index < size && index >= 0) {  // checking the bounds condition
		m_data[index] = source;
	}
	else {
		throw OutOfBoundsException(index);//OutOfBoundsException
	}
}
template <typename T>
T& Array<T>::GetElement(const int index) const {
	// we declare an internal try catch so that we can differentiate between which method is throwing the OutOfBounds
	if (index < size && index >= 0) {  // checking the bounds condition
		return m_data[index];
	}
	else {
		throw OutOfBoundsException(index);//throwing OutOfBoundsException
	}
}
#endif