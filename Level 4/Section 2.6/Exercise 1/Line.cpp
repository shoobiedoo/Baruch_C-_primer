// MP Implementation of the Line segment .cpp

#include "Line.h"
#include <sstream>
#include <string>
#include <cmath>

namespace ShubhankitSingh {
	namespace CAD {
		Line::Line()
		{
			startPoint = Point(0, 0);
			endPoint = Point(0, 0);
			cout << "Default Constructor which initialises both point to (0,0)";

		}

		Line::~Line()
		{
			cout << "Line Destroyed" << endl;
		}

		Line::Line(const Point& p1, const Point& p2)//parameterized constructor
		{
			startPoint = p1;
			endPoint = p2;
		}

		Line::Line(const Line& l) // copy constructor
		{
			startPoint = l.startPoint;
			endPoint = l.endPoint;
		}
		//assignment operator overloading as in the canonical header file
		Line& Line::operator = (const Line& l)
		{
			// Avoid doing assign to myself
			if (this == &l) {
				cout << "Avoiding self assigning" << endl;
				return *this;
			}

			startPoint = l.startPoint;
			endPoint = l.endPoint;

			return *this;
		}
		Point Line::start() const //overloaded getter for the startpoint
		{
			return startPoint;
		}

		Point Line::end() const //overloaded getter for the endpoint
		{
			return endPoint;
		}

		void Line::start(const Point& pt) // overloaded setter for the start point
		{
			startPoint = pt;
		}

		void Line::end(const Point& pt) // overloaded setter for the end point
		{
			endPoint = pt;
		}

		double Line::Length() const {//returns the length of the line by using the underlying distance method attached to the starting point object
			return startPoint.Distance(endPoint);//using the embedded distance method in the point object
		}

		string Line::ToString() const {
			ostringstream temp;
			temp << "Line(" << startPoint.ToString() << "," << endPoint.ToString() << ")" << endl;
			return temp.str();
		}
	}
}