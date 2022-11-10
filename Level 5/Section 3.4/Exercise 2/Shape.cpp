// Shape.cpp
#include "Shape.h"
#include <sstream>
#include <string>
#include <cmath>
Shape::Shape() : id(rand())
{//Default constructor using colon however not an effective change
	cout << "Shape created using default constructor with id initialized to " << id << endl;
}
Shape::Shape(const Shape& s1)//Copy Constructor to copy the coordinates from Shape 1
{
	id = s1.id;
	cout << "Shape created using copy constructor" << endl;
}

Shape::Shape(int idnew) : id(idnew)// Parameterized constructor not needed for this exercise
{// Initialize using newid
	cout << "Shape created using parameterized constructor with id " << id<< endl;
}
Shape::~Shape()
{// Destructor
	cout << "Shape destroyed" << endl;//Display message of the destructor for checking the overall functionality of the Shape destructor
}

//operator overloading
Shape& Shape::operator = (const Shape& s)
{
	// Avoid doing assign to myself
	if (this == &s) {
		cout << "Avoiding self assigning" << endl;
		return *this;
	}
	id = s.id;
	cout << "Assignment operator is used for assigning Shapes" << endl;
	return *this;
}
//getter for shape ID
int Shape::ID() const
{
	return id;
}

// Modifiers
// Set the id value 
void Shape::ID(int newid)//overloaded id function as setter not required for this exercise
{
	id = newid;
}

//To string method for printing the description of the Shape itself
string Shape::ToString() const {
	ostringstream temp;//defining the output string stream
	temp << "Shape(" <<id << ")";//returning the description about the Shape's coordinates
	return temp.str();
}

//operator overloading for << 
ostream& operator << (ostream& os, const Shape& s) {
	os << s.ToString();
	return os;
}