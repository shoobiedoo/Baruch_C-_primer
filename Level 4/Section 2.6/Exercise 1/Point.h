// point.hpp
// Simple two dimensional point consisting of a x and y 
// value

#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
namespace ShubhankitSingh {
	namespace CAD {
		class Point
		{
		private:
			double x; // X value of point
			double y; // Y value of point
		public:
			// Constructors and destructor
			Point(); // Default constructor
			Point(const Point& p);
			Point(double xval, double yval);
			~Point(); // Destructor
			//Selectors
			double X() const; // Access the x value
			double Y() const; // Access the y value
			// Modifiers
			void X(double newxval); // Set the x value
			void Y(double newyval); // Set the y value
			//Operators 
			Point operator - () const; // Negate the coordinates.
			Point operator * (double factor) const; // Scale the coordinates.
			Point operator + (const Point& p) const; // Add coordinates.
			bool operator == (const Point& p) const; // Equally compare operator.
			Point& operator = (const Point& source); // Assignment operator.
			Point& operator *= (double factor); // Scale the coordinates & assign.
			//To String Method
			string ToString() const;
			double Distance() const;//Function to find the distance of the current point from origin 
			double Distance(const Point& pt) const;// Function to find the distance of the current point from point one to point two
			
			//friend function
			friend ostream& operator << (ostream& os, const Point& p);
		};
	}
}
#endif
