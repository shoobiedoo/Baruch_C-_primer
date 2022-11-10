// TestSingleCurve.cpp
//
// Displaying a single curve on one Excel sheet.
//
// Modification dates:
//
// 2007-3-3 DD Kick-offs
// 2007-7-23 DD Some schemes (e.g. IE added)
// 2007-7-27 DD derivative-free scheme
// 2009-6-14 DD clean up
// 2012-1-17 DD for QN
// 2017-3-14 DD Lite version
//
// (C) Datasim Education BV 2005-2017
//

#include "ExcelDriverLite.hpp"
#include "Utilities.hpp"
#include <cmath>
#include <list>
#include <string>
#include <vector>

int main()
{
	// DON'T FORGET TO MODIFY EXCELIMPORTS.CPP for correct version of Excel.

	long N = 40;

	// Create abscissa x array
	double A = 0.0;  double B = 10.0;
	auto x = CreateMesh(N, A,B);

	auto fun = [](double x) { return x*x; };
	auto vec1 = CreateDiscreteFunction< std::vector<double>>(x, fun);

	ExcelDriver xl; xl.MakeVisible(true);
	xl.CreateChart(x, vec1, "Test 101 curve on (0,10)");

	return 0;
}
