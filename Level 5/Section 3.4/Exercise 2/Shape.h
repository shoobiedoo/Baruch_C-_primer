// Shape.h
// Base class for all the shapes

#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;
class Shape
{
private:
	int id; // id for the shape
public:
	// Constructors and destructor
	Shape(); // Default constructor
	Shape(const Shape& p);
	Shape(int id);
	~Shape(); // Destructor
	//Selectors
	int ID() const;
	//Modifier
	void ID(int id);

	//Operators
	Shape& operator = (const Shape& source); // Assignment operator.
	//To String Method
	string ToString() const;
	};

//declaring as a global function inside the header file but outside the class declaration
ostream& operator << (ostream& os, const Shape& p);
#endif
