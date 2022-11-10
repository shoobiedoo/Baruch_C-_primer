#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
//defining the template name as type T
template <typename T>
class Array
{
private:
	static int defaultSize;
	T* m_data;
	int size;
public:
	Array();//default constructor
	Array(int size);//parametrized size constructor
	Array(const Array& a);// copy constructor
	virtual ~Array();//destructor declared cirtual so even the derived class destructor is called
	static void DefaultSize(int newDefSize);//static function for setting static member
	static int DefaultSize();//returns static member by a public function

	int Size() const;//returns the size of the array
	T& GetElement(const int index) const;//getter
	void SetElement(const int index, T& source);//setter
	Array& operator = (const Array& a);//canonical assignment operator
	const T& operator [] (int index) const;//overloading the [] operator to access elements
	T& operator [] (int index);//overloading the [] opreator without const operator to assign values to the point
};
#ifndef Array_CPP // Same as in the source file 
#include "Array.cpp"
#endif
#endif