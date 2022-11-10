#include "Array.h"
#include "Point.h"

Array::Array() {
	cout << "Default constructor is called" << endl;
	m_data = new Point[10];
	size = 10;
}
Array::Array(int sz) {
	cout << "size constructor creating an array of size: "<< sz << endl;
	m_data = new Point[sz];
	size = sz;
}
Array::Array(const Array& a) {
	cout << "Copy constructor is called to create an array of size "<<a.size<< endl;
	size = a.size;
	m_data = new Point[size];
	for (int i = 0; i < size; i++) {
		m_data[i] = a.m_data[i];
	}
}
Array::~Array() {
	delete [] m_data;
	cout << "Default destructor deleting array of size: "<< size << endl;
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
	delete [] m_data;
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
// [] operator to just get the vakue at the particular index of the array
const Point& Array::operator [] (int index) const {
	return m_data[index];
}
// to assign to the particular array index location
Point& Array::operator [] (int index) {
	return m_data[index];
}
void Array::SetElement(const int index,Point &source) {
	if (index < size) {
		m_data[index] = source;
	}
}

Point& Array::GetElement(const int index) {
	if (index >= size)
		return m_data[0];
	return m_data[index];
}