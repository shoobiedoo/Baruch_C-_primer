#ifndef ARRAY_H
#define ARRAY_H
#include "Point.h"
#include <iostream>
using namespace std;
namespace ShubhankitSingh {
	using CAD::Point;//including point class without including ShubhankitSingh namespace
	namespace Containers{
		class Array
		{
		private:
			Point* m_data;
			int size;
		public:
			Array();
			Array(int size);
			Array(const Array& a);
			Array(Point* p);
			~Array();

			int Size() const;
			Point& GetElement(const int index);
			void SetElement(const int index, Point& source);
			Array& operator = (const Array& a);
			const Point& operator [] (int index) const;;
			Point& operator [] (int index);
		};
	}
}
#endif