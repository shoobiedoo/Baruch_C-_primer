#ifndef POINTARRAY_H
#define POINTARRAY_H
#include <iostream>
#include "array.h"
using namespace std;
//concrete inheritance of the Array<Point> class which is a part of the Array template 
class PointArray : public Array<Point>
{
private:
public:
	PointArray();//default constructor
	PointArray(int size);//parametrized size constructor
	PointArray(const PointArray& a);// copy constructor
	~PointArray();//destructor
	PointArray& operator = (const PointArray& a);//canonical assignment operator
	double Length() const;//length function which returns the distance between consecutive poitns

};
#endif