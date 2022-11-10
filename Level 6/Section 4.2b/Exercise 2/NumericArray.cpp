
#ifndef NumericArray_CPP
#define NumericArray_CPP
#include "NumericArray.h"
#include "OutOfBoundsException.h"
#include "ArraySizeMismatchException.h"
#include "ArrayException.h"
#include "Array.h"
#include "Point.h"

template <typename T>
NumericArray<T>::NumericArray(): Array<T>() {
	//initializing the m_size with the default Size() in the default constructor
	cout << "Default constructor is called to create numeric array of Size() : " << this->Size() << endl;
}
template <typename T>
NumericArray<T>::NumericArray(int sz): Array<T>(sz) {
	cout << "Size() constructor creating an numeric array of Size(): " << sz << endl;
}
template <typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& a) :Array<T>(a){
	cout << "Copy constructor is called to create an array of Size() " << a.Size() << endl;
}
template <typename T>
NumericArray<T>::~NumericArray() {
	cout << "Default destructor deleting numeric array of Size(): " << this->Size() << endl;
}
//assignment operator overloading as in the canonical header file
template <typename T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& a)
{
	cout << "Assigning array to new Array of Size(): " << a.Size() << endl;

	// Avoid doing assign to myself
	if (this == &a) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}
	Array<T>::operator = (a);
	cout << "Before assigning deleting the existing array of Size() " << this->Size() << endl;
	return *this;
}


// [] operator to just get the value at the particular index of the array
template <typename T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T> &a) const {
	// we declare an internal try catch so that we can differentiate between which method is throwing the OutOFBounds
	if (a.Size() != this->Size()) {
		throw ArraySizeMismatchException(a.Size(), this->Size());
	}
	NumericArray<T> temp(this->Size());
	for (int i = 0; i < this->Size(); i++) {
		temp[i] = (*this)[i] + a[i];
	}
	return temp;
	}

template<typename T>
T NumericArray<T>::DotProduct(const NumericArray& a) const
{
	if (a.Size() != this->Size()) {
		throw ArraySizeMismatchException(a.Size(),this->Size());
	}
	T dot = 0;
	for (int i = 0; i < this->Size(); i++) {
		dot += (*this)[i] * a[i];
	}
	return dot;
}

template<typename T>
NumericArray<T> NumericArray<T>::operator * (int scale) const
{	//scaling the array elements
	NumericArray<T> temp(this->Size());
	for (int i = 0; i < this->Size(); i++) {
		temp[i] = (*this)[i] * scale;
	}
	return temp;
}
#endif