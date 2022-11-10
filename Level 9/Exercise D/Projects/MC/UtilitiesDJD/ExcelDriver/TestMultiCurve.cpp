// TestMultiCurve.cpp
//
// Displaying multiple curves on one Excel sheet.
//
// Modification dates:
//
// 2007-3-3 DD Kick-offs
// ...
// 2012-1-17 DD for QN
//
// 2017-3-14 DD new version
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
	double A = 0.0; double B = 3.0; // Interval
	auto x = CreateMesh(N, A, B);

	auto fun = [](double x) { return std::log(x+ 0.01); };
	auto fun2 = [](double x) { return x*x; };
	auto fun3= [](double x) { return x*x*x; };
	auto fun4 = [](double x) { return std::exp(x); };
	auto fun5 = [](double x) { return x; };

	// Exx.Higher order functions in C++11 g = f op h, e.g. g = f - h

	auto vec1 = CreateDiscreteFunction< std::vector<double>>(x, fun);
	auto vec2 = CreateDiscreteFunction< std::vector<double>>(x, fun2);
	auto vec3 = CreateDiscreteFunction< std::vector<double>>(x, fun3);
	auto vec4 = CreateDiscreteFunction< std::vector<double>>(x, fun4);
	auto vec5 = CreateDiscreteFunction< std::vector<double>>(x, fun5);
	// Now Excel output in one sheet for comparison purposes

	// Names of each vector

	// C++11 syntax:
	//std::list<std::string> labels{ "log(x+0.01)", "x^2", "x^3", "exp(x)","x" };
	std::list<std::string> labels;
	labels.push_back("log(x+0.01)");
	labels.push_back("x^2");
	labels.push_back("x^3");
	labels.push_back("exp(x)");
	labels.push_back("x");

	// The list of Y values

	// C++11 syntax:
	// std::list<std::vector<double> > curves{ vec1, vec2, vec3, vec4, vec5 };
	std::list<std::vector<double> > curves;
	curves.push_back(vec1);
	curves.push_back(vec2);
	curves.push_back(vec3);
	curves.push_back(vec4);
	curves.push_back(vec5);

	std::cout << "Data has been created\n";


	ExcelDriver xl; xl.MakeVisible(true);
	xl.CreateChart(x, labels, curves, "Comparing Functions", "x", "y");

	return 0;
}
