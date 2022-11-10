#ifndef ARRAY_H
#define ARRAY_H
#include "Point.h"
#include <iostream>
using namespace std;

class Array
{
private:
	Point* m_data;
	int size;
public:
	Array();//default constructor
	Array(int size);//parametrized size constructor
	Array(const Array& a);// copy constructor
	~Array();//destructor

	int Size() const;
	Point& GetElement(const int index) const;//getter
	void SetElement(const int index, Point& source);//setter
	Array& operator = (const Array& a);//canonical assignment operator
	const Point& operator [] (int index) const;//overloading the [] operator to access elements
	Point& operator [] (int index);//overloading the [] opreator without const operator to assign values to the point
};
#endif