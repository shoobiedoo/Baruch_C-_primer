#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
//defining the template name as type T
template <typename T>
class Array
{
private:
	static int defaultSize;//declaring the static int member
	T* m_data;// declaring the array pointer
	int size;//declaring the member size
public:
	Array();//default constructor
	Array(int size);//parametrized size constructor
	Array(const Array& a);// copy constructor
	~Array();//destructor
	static void DefaultSize(int newDefSize);//static method to set Default Size
	static int DefaultSize();//static method to fetch Default size

	int Size() const;
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