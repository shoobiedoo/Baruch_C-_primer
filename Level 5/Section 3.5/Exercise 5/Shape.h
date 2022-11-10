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
	virtual ~Shape(); // Destructor declared virtual so that the derived destructors will also be called
	//Selectors
	int ID() const;
	//Modifier
	void ID(int id);

	//Operators
	Shape& operator = (const Shape& source); // Assignment operator.
	//To String Method declared as virtual so that it can be overridden by the derived class
	virtual string ToString() const;
	// Draw method 
	virtual void Draw() const = 0;
	//print method using ToString's polymorphic behaviour
	void Print() const;
};

//declaring as a global function inside the header file but outside the class declaration
ostream& operator << (ostream& os, const Shape& p);
#endif
