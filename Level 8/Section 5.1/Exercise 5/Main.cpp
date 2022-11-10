// Main.cpp
//
// First program test the Boost statistics library.
//
// Look at the Exponential and Poisson distribution and how boosts handles them 
//

#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
#include <vector>
#include <iostream>
using namespace std;


int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;
	double scaleParameter = 0.5;
	// Default type is 'double'
	cout << "*** Exponential Distribution " << endl;
	exponential_distribution<> myExponential(scaleParameter);
	cout << "Mean: " << mean(myExponential) << ", standard deviation: " << standard_deviation(myExponential) << endl;

	// Distributional properties
	double x = 10.25;

	cout << "pdf: " << pdf(myExponential, x) << endl;
	cout << "cdf: " << cdf(myExponential, x) << endl;

	// Choose another data type and now a default exponential 
	exponential_distribution<float> myExponential2;
	cout << "Mean: " << mean(myExponential2) << ", standard deviation: " << standard_deviation(myExponential2) << endl;

	cout << "pdf: " << pdf(myExponential2, x) << endl;
	cout << "cdf: " << cdf(myExponential2, x) << endl;

	// Choose precision
	cout.precision(10); // Number of values behind the comma

	// Other properties
	cout << "\n***exponential distribution: \n";
	cout << "mean: " << mean(myExponential) << endl;
	cout << "variance: " << variance(myExponential) << endl;
	cout << "median: " << median(myExponential) << endl;
	cout << "mode: " << mode(myExponential) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
	cout << "kurtosis: " << kurtosis(myExponential) << endl;
	cout << "characteristic function: " << chf(myExponential, x) << endl;
	cout << "hazard: " << hazard(myExponential, x) << endl;


	cout << "*** Poisson Distribution" << endl;
	double mean = 3.0;//mean of the poisson distribution 
	poisson_distribution<double> myPoisson(mean);//defining poisson distribution 
	double val = 13.0;
	cout << endl << "pdf: " << pdf(myPoisson, val) << endl;
	cout << "cdf: " << cdf(myPoisson, val) << endl;

	vector<double> pdfList;
	vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myPoisson, val));
		cdfList.push_back(cdf(myPoisson, val));
		val += h;
	}

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";
	}

	cout << "***" << endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";
	}

	return 0;
}