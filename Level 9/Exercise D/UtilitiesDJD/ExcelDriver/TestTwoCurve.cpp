// TestTwoCurve.cpp
//
// Displaying TWO curves on one Excel sheet.
//
// Modification dates:
//
// 2007-3-3 DD Kick-offs
// ..
// 2017-3-14 DD new version
//
// (C) Datasim Education BV 2005-2017
//

#include "ExcelDriverLite.hpp"
#include "Utilities.hpp"

#include <cmath>
#include <list>
#include <string>
#include <iostream>

int main()
{
	// DON'T FORGET TO MODIFY EXCELIMPORTS.CPP for correct version of Excel.

	long N = 40;
	

	// Create abscissa x array
	double T = 10.0;
	auto x = CreateMesh(N, 0.0, T);

	auto fun = [](double x) { return x*x; };
	auto fun2 = [](double x) { return x*x*x; };
	auto vec1 = CreateDiscreteFunction< std::vector<double>>(x, fun);
	auto vec2 = CreateDiscreteFunction< std::vector<double>>(x, fun2);

	ExcelDriver xl; xl.MakeVisible(true);
	xl.CreateChart(x, vec1, "x^2");
	xl.CreateChart(x, vec2, "x^3");

	// C++11 style initializer lists
	// std::list<std::string> labels{ "x^2", "x^3" };
	std::list<std::string> labels;
	labels.push_back("x^2");
	labels.push_back("x^3");

	// C++11 style initializer lists
	// std::list<std::vector<double>> curves{ vec1, vec2 };
	std::list<std::vector<double>> curves;
	curves.push_back(vec1);
	curves.push_back(vec2);

	xl.CreateChart(x, labels, curves, "Polynomial Curves", "H", "V");
	
	return 0;
}
