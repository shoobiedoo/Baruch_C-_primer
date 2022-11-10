

#include "PointArray.h"
#include "OutOfBoundsException.h"
#include "ArrayException.h"
#include "Array.h"
#include "Point.h"
//concrete inheritance of the Array<Point>() class
PointArray::PointArray() : Array<Point>() {
	//initializing the m_size with the default Size() in the default constructor
	cout << "Default constructor is called to create point array of Size() : " << this->Size() << endl;
}

PointArray::PointArray(int sz) : Array<Point>(sz) {
	cout << "Size() constructor creating an point array of Size(): " << sz << endl;
}

PointArray::PointArray(const PointArray& a) : Array<Point>(a) {
	cout << "Copy constructor is called to create an array of Size() " << a.Size() << endl;
}

PointArray::~PointArray() {
	cout << "Default destructor deleting numeric array of Size(): " << this->Size() << endl;
}
//assignment operator overloading as in the canonical header file
PointArray& PointArray::operator = (const PointArray& a)
{
	// Avoid doing assign to myself
	if (this == &a) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}
	cout << "Assigning array to new Array of Size(): " << a.Size() << endl;
	Array<Point>::operator = (a);
	cout << "Before assigning deleting the existing array of Size() " << this->Size() << endl;
	return *this;
}

double PointArray::Length() const
{
	double sum = 0;//initial sum of distances
	for (int i = 0; i < this->Size()-1; i++) {
		sum += (*this)[i].Distance((*this)[i + 1]); // distance between consecutive points 
	}
	return sum;
}
