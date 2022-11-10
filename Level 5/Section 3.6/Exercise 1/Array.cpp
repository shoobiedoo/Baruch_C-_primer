#include "Array.h"
#include "Point.h"

Array::Array() {
	cout << "Default constructor is called" << endl;
	m_data = new Point[10];
	size = 10;
}
Array::Array(int sz) {
	cout << "size constructor creating an array of size: " << sz << endl;
	m_data = new Point[sz];
	size = sz;
}
Array::Array(const Array& a) {
	cout << "Copy constructor is called to create an array of size " << a.size << endl;
	size = a.size;
	m_data = new Point[size];
	for (int i = 0; i < size; i++) {
		m_data[i] = a.m_data[i];
	}
}
Array::~Array() {
	delete[] m_data;
	cout << "Default destructor deleting array of size: " << size << endl;
}
//assignment operator overloading as in the canonical header file
Array& Array::operator = (const Array& a)
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
	m_data = new Point[size];
	for (int i = 0; i < size; i++) {
		m_data[i] = a.m_data[i];
	}
	return *this;
}
int Array::Size() const {
	return size;
}
// [] operator to just get the value at the particular index of the array
const Point& Array::operator [] (int index) const {
	// we could also declare an internal try catch so that we can differentiate between which method is throwing the -1
	if (index < size && index >= 0) {  // checking the bounds condition
		return m_data[index];
	}
	else {
		cout << "index operator (accessing) Throwing -1 as index is " << index;
		throw - 1; // throwing -1 
	}
}
// to assign to the particular array index location
Point& Array::operator [] (int index) {
	// we could also declare an internal try catch so that we can differentiate between which method is throwing the -1
	if (index < size && index >= 0) { // checking the bounds condition
		return m_data[index];
	}
	else {
		cout << "index operator (assigning) Throwing -1 as index is " << index;
		throw - 1;//throwing -1
	}
}
void Array::SetElement(const int index, Point& source) {
	// we could also declare an internal try catch so that we can differentiate between which method is throwing the -1
	if (index < size && index >= 0) {  // checking the bounds condition
		m_data[index] = source;
	}
	else {
		cout << "SetElement Throwing -1 as index is " << index;
		throw - 1;//throwing -1
	}
}

Point& Array::GetElement(const int index) const {
	// we could also declare an internal try catch so that we can differentiate between which method is throwing the -1
	if (index < size && index >= 0) {  // checking the bounds condition
		return m_data[index];
	}
	else {
		cout << "GetElement Throwing -1 as index is " << index;
		throw - 1;//throwing -1
	}
}