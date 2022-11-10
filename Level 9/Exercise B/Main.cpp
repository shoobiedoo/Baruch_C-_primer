// TestEuropeanOption.cpp
//
// Test program for the exact solutions of European options.
//

#include "Option.h"
#include "PerpetualAmericanOption.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
Cost of carry factor b must be included in formulae depending on the
derivative type. These are used in the generalised Black-Scholes formula.
If r is the risk-free interest and q is the continuous dividend yield then
the cost-of-carry b per derivative type is:

a) Black-Scholes (1973) stock option model: b = r
b) b = r - q Merton (1973) stock option model with continuous dividend yield
c) b = 0 Black (1976) futures option model
d) b = r - rf Garman and Kohlhagen (1983) currency option model, where rf is the
'foreign' interest rate
*/

void main()
{
	ofstream fout("output.txt");

	//////////  Option prices  //////////

	double K, sig, r, U, b; 
	K = 100; sig = 0.1; r = 0.1; b = 0.02; U = 110;
	vector <vector <vector<double>> > meshMatrix;
	meshMatrix.push_back({});
	vector<double> vecU = GenerateMeshArray(10, 110.0, 101);

	// B.b)
	// Use global functions.
	cout << "Testing for the given case (S,K,sig,r,b) = (" << U << "," << K << "," << sig << "," << r << "," << b << ")" << endl;
	cout << "S = " << U << ", C = " << PerpetualCall(K, sig, r, U, b) << ", P = " << PerpetualPut(K, sig, r, U, b) << endl;
	fout << "S = " << U << ", C = " << PerpetualCall(K, sig, r, U, b) << ", P = " << PerpetualPut(K, sig, r, U, b) << endl;

	// Use instances of PerpetualAmericanOption class.
	PerpetualAmericanOptionData optionData;
	optionData.K = K;
	optionData.sig = sig;
	optionData.r = r;
	optionData.U = U;
	optionData.b = b;
	cout << "Testing the same case using an instance of the American Option class" << endl;
	PerpetualAmericanOption perpetualOption(optionData);
	cout << "S = " << U << ", C = " << perpetualOption.Price() << endl;
	fout << "S = " << U << ", C = " << perpetualOption.Price() << endl;
	perpetualOption.toggle();
	cout << "S = " << U << ", P = " << perpetualOption.Price() << endl;
	fout << "S = " << U << ", P = " << perpetualOption.Price() << endl;
	perpetualOption.toggle();

	// B.c and d)
	// Compute prices for a range of underlying value and applying the matrix pricer code 
	vector<double> vecC1, vecP1;
	for (int j = 0; j < vecU.size(); j++)
	{
		vecC1.push_back(perpetualOption.PriceWithS(vecU[j]));
		perpetualOption.toggle();
		vecP1.push_back(perpetualOption.PriceWithS(vecU[j]));
		perpetualOption.toggle();
	}
	meshMatrix[0].push_back(vecC1);
	meshMatrix[0].push_back(vecP1);
	//final mesh matrix display for american perpetual options put and calls
	for (int j = 0; j < vecC1.size(); j++)
	{
		cout << "S = " << vecU[j] << ", C = " << meshMatrix[0][0][j] << ", P = " << meshMatrix[0][1][j] << endl;
		fout << "S = " << vecU[j] << ", C = " << meshMatrix[0][0][j] << ", P = " << meshMatrix[0][1][j] << endl;
	}

	fout << flush;
	fout.close();
}