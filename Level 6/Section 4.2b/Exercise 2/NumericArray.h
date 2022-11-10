#ifndef NUMERICARRAY_H
#define NUMERICARRAY_H
#include <iostream>
#include "array.h"
using namespace std;
//defining the template name as type T
template <typename T>
class NumericArray : public Array<T> //general inheritance
{
private:
public:
	NumericArray();//default constructor
	NumericArray(int size);//parametrized size constructor
	NumericArray(const NumericArray& a);// copy constructor
	~NumericArray();//destructor
	NumericArray& operator = (const NumericArray& a);//canonical assignment operator
	NumericArray operator + (const NumericArray& a) const;//adding the corresponding elements
	NumericArray operator * (int scale) const;//we can scale with type T as well but point numeric array wont support it 
	T DotProduct(const NumericArray& a) const;//gives the dot product but is bound to fail if there is no T*T operator overloading

	
};
#ifndef NumericArray_CPP // Same as in the source file 
#include "NumericArray.cpp"
#endif
#endif