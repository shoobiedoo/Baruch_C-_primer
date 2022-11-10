// TestEuropeanOption.cpp
//
// Test program for the exact solutions of European options.
//


#include "Option.h"
#include "EuropeanOption.h"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
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

void testEuropeanOption() {
	// Store Batch 1 to Batch 4 data in a vector.
	typedef boost::tuple<double, double, double, double, double> TupleFive;
	vector<TupleFive> vecBatch;
	vecBatch.push_back(boost::make_tuple(0.25, 65.0, 0.30, 0.08, 60.0));
	vecBatch.push_back(boost::make_tuple(1.0, 100.0, 0.2, 0.0, 100.0));
	vecBatch.push_back(boost::make_tuple(1.0, 10.0, 0.50, 0.12, 5.0));
	vecBatch.push_back(boost::make_tuple(30.0, 100.0, 0.30, 0.08, 100.0));
	ofstream fout("output.txt");
	vector <vector <vector<double>> > meshMatrix;
	///  Option prices (stock option, b = r by default)  //////////
	double T, K, sig, r, U, b;
	double C, P;
	int n = 41;

	vector<double> vecU = GenerateMeshArray(10.0, 50.0, n);
	vector<double> vecT = GenerateMeshArray(0.1, 1.0, n);
	vector<double> vecSig = GenerateMeshArray(0.1, 1.0, n);

	for (int i = 0; i < vecBatch.size(); i++)
	{
		meshMatrix.push_back({});
		// A.1.a)
		// Use global functions.
		T = vecBatch[i].get<0>();
		K = vecBatch[i].get<1>();
		sig = vecBatch[i].get<2>();
		r = vecBatch[i].get<3>();
		U = vecBatch[i].get<4>();
		b = r;
		cout << "Checking put and call price using global function : " << endl;
		C = CallPrice(T, K, sig, r, U, b);
		P = PutPrice(T, K, sig, r, U, b);
		cout << "Batch " << i + 1 << ": C = " << C << ", P = " << P << endl;
		fout << "Batch " << i + 1 << ": C = " << C << ", P = " << P << endl;
		
		// Use instances of EuropeanOption class with default constructor.
		cout << "Using an instance of european option class" << endl;
		EuropeanOption option0;
		option0.T = T;
		option0.K = K;
		option0.sig = sig;
		option0.r = r;
		option0.U = U;
		option0.b = b;
		cout << "Batch " << i + 1 << ":" << endl << "C = " << option0.Price() << endl;
		fout << "Batch " << i + 1 << ":" << endl << "C = " << option0.Price() << endl;
		option0.toggle();
		cout << "P = " << option0.Price() << endl;
		fout << "P = " << option0.Price() << endl;

		// A.1.b)
		// Use put-call parity.
		cout << "Checking put call parity" << endl;
		cout << "Checking Call price by converting put to call" << endl;
		cout << "Batch " << i + 1 << ":" << endl << "C = " << option0.PutToCall(option0.Price()) << endl;
		fout << "Batch " << i + 1 << ":" << endl << "C = " << option0.PutToCall(option0.Price()) << endl;
		option0.toggle();
		cout << "Checking Put price by converting call to put" << endl;
		cout << "P = " << option0.CallToPut(option0.Price()) << endl;
		fout << "P = " << option0.CallToPut(option0.Price()) << endl;

		//using a struct to aggregate all option parameters
		EuropeanOptionData optionData;
		optionData.T = T;
		optionData.K = K;
		optionData.sig = sig;
		optionData.r = r;
		optionData.U = U;
		optionData.b = b;

		// A.1.c)
		// Use constructor with EuropeanOptionData and calculate option price as a function of underlying price.
		EuropeanOption option1(optionData);
		cout << "Calculating option price as a function of underlying price" << endl;
		cout << "Batch " << i + 1 << ":" << endl << "C = " << option1.PriceWithS(U) << endl;
		fout << "Batch " << i + 1 << ":" << endl << "C = " << option1.PriceWithS(U) << endl;
		option1.toggle();
		cout << "P = " << option1.PriceWithS(U) << endl;
		fout << "P = " << option1.PriceWithS(U) << endl;
		option1.toggle();

		// A.1.d)
		// Compute prices for a range of underlying value.
		vector<double> vecC1, vecP1;
		for (int j = 0; j < vecU.size(); j++)
		{
			vecC1.push_back(option1.PriceWithS(vecU[j]));
			option1.toggle();
			vecP1.push_back(option1.PriceWithS(vecU[j]));
			option1.toggle();
		}

		meshMatrix[i].push_back(vecC1);
		meshMatrix[i].push_back(vecP1);

		// A.1.d)
		// Use constructor with EuropeanOptionData and calculate option price as a function of expiry time.
		cout << "Calculating Option prices as a function of expiry time " << endl;
		EuropeanOption option2(optionData);
		cout << "Batch " << i + 1 << ":" << endl << "C = " << option2.PriceWithT(T) << endl;
		fout << "Batch " << i + 1 << ":" << endl << "C = " << option2.PriceWithT(T) << endl;
		option2.toggle();
		cout << "P = " << option2.PriceWithT(T) << endl;
		fout << "P = " << option2.PriceWithT(T) << endl;
		option2.toggle();

		// Compute prices for a range of expiry time.
		vector<double> vecC2, vecP2;
		for (int j = 0; j < vecT.size(); j++)
		{
			vecC2.push_back(option2.PriceWithT(vecT[j]));
			option2.toggle();
			vecP2.push_back(option2.PriceWithT(vecT[j]));
			option2.toggle();
		}

		meshMatrix[i].push_back(vecC2);
		meshMatrix[i].push_back(vecP2);

		// Use constructor with EuropeanOptionData and calculate option price as a function of volatility.
		EuropeanOption option3(optionData);
		cout << "Batch " << i + 1 << ":" << endl << "C = " << option3.PriceWithSig(sig) << endl;
		fout << "Batch " << i + 1 << ":" << endl << "C = " << option3.PriceWithSig(sig) << endl;
		option3.toggle();
		cout << "P = " << option3.PriceWithSig(sig) << endl;
		fout << "P = " << option3.PriceWithSig(sig) << endl;
		option3.toggle();

		// Compute prices for a range of volatility.
		vector<double> vecC3, vecP3;
		for (int j = 0; j < vecSig.size(); j++)
		{
			vecC3.push_back(option3.PriceWithSig(vecSig[j]));
			option3.toggle();
			vecP3.push_back(option3.PriceWithSig(vecSig[j]));
			option3.toggle();
		}
		meshMatrix[i].push_back(vecC3);
		meshMatrix[i].push_back(vecP3);
		cout << endl;
		fout << endl;
	}
	cout << "final mesh matrix" << endl;
	//meshmatrix is the final output
	//now mesh matrix contains a vectors of vector of vector for all 3 types of ranges for underlying stock , expiry time and volatility
	// for all 4 batches of options for both put and call
	for (int i = 0; i < meshMatrix.size();i++) {
		vector<vector<double> > currentOption = meshMatrix[i];
		for (int j = 0; j < vecU.size(); j++)
		{
			cout << "Batch " << i + 1 << ": S = " << vecU[j] << ", C = " << currentOption[0][j] << ", P = " << currentOption[1][j] << endl;
			fout << "Batch " << i + 1 << ": S = " << vecU[j] << ", C = " << currentOption[0][j] << ", P = " << currentOption[1][j] << endl;
		}
		for (int j = 0; j < vecT.size(); j++)
		{
			cout << "Batch " << i + 1 << ": T = " << vecT[j] << ", C = " << currentOption[2][j] << ", P = " << currentOption[3][j] << endl;
			fout << "Batch " << i + 1 << ": T = " << vecT[j] << ", C = " << currentOption[2][j] << ", P = " << currentOption[3][j] << endl;
		}
		for (int j = 0; j < vecSig.size(); j++)
		{
			cout << "Batch " << i + 1 << ": Sig = " << vecSig[j] << ", C = " << currentOption[4][j] << ", P = " << currentOption[5][j] << endl;
			fout << "Batch " << i + 1 << ": Sig = " << vecSig[j] << ", C = " << currentOption[4][j] << ", P = " << currentOption[5][j] << endl;
		}
	}
	cout << endl;
	//////////  Option sensitivities (stock option, b = r by default)  //////////
	T = 0.5;
	K = 100;
	sig = 0.36;
	r = 0.1;
	U = 105;
	b = 0.0;

	// A.2.a)
	// Use global functions.
	cout << "Delta of Call = " << CallDelta(T, K, sig, r, U, b) << ", Delta of Put = " << PutDelta(T, K, sig, r, U, b) << endl;
	fout << "Delta of Call = " << CallDelta(T, K, sig, r, U, b) << ", Delta of Put = " << PutDelta(T, K, sig, r, U, b) << endl;
	cout << "Gamma of Call = " << CallGamma(T, K, sig, r, U, b) << ", Gamma of Put = " << PutGamma(T, K, sig, r, U, b) << endl;
	fout << "Gamma of Call = " << CallGamma(T, K, sig, r, U, b) << ", Gamma of Put = " << PutGamma(T, K, sig, r, U, b) << endl;
	cout << endl;
	fout << endl;

	// Use instances of EuropeanOption class.
	EuropeanOption futureOption;
	futureOption.T = T;
	futureOption.K = K;
	futureOption.sig = sig;
	futureOption.r = r;
	futureOption.U = U;
	futureOption.b = b;
	cout << "Delta of Call = " << futureOption.Delta() << endl;
	fout << "Delta of Call = " << futureOption.Delta() << endl;
	cout << "Gamma of Call = " << futureOption.Gamma() << endl;
	fout << "Gamma of Call = " << futureOption.Gamma() << endl;
	futureOption.toggle();
	cout << "Delta of Put = " << futureOption.Delta() << endl;
	fout << "Delta of Put = " << futureOption.Delta() << endl;
	cout << "Gamma of Put = " << futureOption.Gamma() << endl;
	fout << "Gamma of Put = " << futureOption.Gamma() << endl;
	futureOption.toggle();
	cout << endl;
	fout << endl;

	// A.2.b)
	// Compute Delta for a range of underlying values.
	vector<double> vecCDelta, vecPDelta;
	for (int i = 0; i < vecU.size(); i++)
	{
		futureOption.U = vecU[i];
		vecCDelta.push_back(futureOption.Delta());
		futureOption.toggle();
		vecPDelta.push_back(futureOption.Delta());
		futureOption.toggle();
	}

	for (int i = 0; i < vecCDelta.size(); i++)
	{
		cout << "S = " << vecU[i] << ", Delta of Call = " << vecCDelta[i] << ", Delta of Put = " << vecPDelta[i] << endl;
		fout << "S = " << vecU[i] << ", Delta of Call = " << vecCDelta[i] << ", Delta of Put = " << vecPDelta[i] << endl;
	}
	cout << endl;
	fout << endl;

	// A.2.c)
	// Use divided differences for A.2.a)
	vector<double> vecH = GenerateMeshArray(0.001, 1, n);
	for (int i = 0; i < vecH.size(); i++)
	{
		cout << "S = " << U << ", h = " << vecH[i] << ", Delta of Call = " << futureOption.DeltaDiff(U, vecH[i]) << endl;
		fout << "S = " << U << ", h = " << vecH[i] << ", Delta of Call = " << futureOption.DeltaDiff(U, vecH[i]) << endl;
		futureOption.toggle();
		cout << "S = " << U << ", h = " << vecH[i] << ", Delta of Put = " << futureOption.DeltaDiff(U, vecH[i]) << endl;
		fout << "S = " << U << ", h = " << vecH[i] << ", Delta of Put = " << futureOption.DeltaDiff(U, vecH[i]) << endl;
		futureOption.toggle();
	}

	for (int i = 0; i < vecH.size(); i++)
	{
		cout << "S = " << U << ", h = " << vecH[i] << ", Gamma of Call = " << futureOption.GammaDiff(U, vecH[i]) << endl;
		fout << "S = " << U << ", h = " << vecH[i] << ", Gamma of Call = " << futureOption.GammaDiff(U, vecH[i]) << endl;
		futureOption.toggle();
		cout << "S = " << U << ", h = " << vecH[i] << ", Gamma of Put = " << futureOption.GammaDiff(U, vecH[i]) << endl;
		fout << "S = " << U << ", h = " << vecH[i] << ", Gamma of Put = " << futureOption.GammaDiff(U, vecH[i]) << endl;
		futureOption.toggle();
	}

	// Use divided differences for A.2.b)
	vector<double> vecCDelta1, vecPDelta1;
	for (int i = 0; i < vecU.size(); i++)
	{
		for (int j = 0; j < vecH.size(); j++)
		{
			vecCDelta1.push_back(futureOption.DeltaDiff(vecU[i], vecH[j]));
			futureOption.toggle();
			vecPDelta1.push_back(futureOption.DeltaDiff(vecU[i], vecH[j]));
			futureOption.toggle();
			// directly outputting the matrix
			cout << "S = " << vecU[i] << ", h = " << vecH[j] << ", Delta of Call = " << vecCDelta1[i + j] << ", Delta of Put = " << vecPDelta1[i + j] << endl;
			fout << "S = " << vecU[i] << ", h = " << vecH[j] << ", Delta of Call = " << vecCDelta1[i + j] << ", Delta of Put = " << vecPDelta1[i + j] << endl;
		}
	}

	fout << flush;
	fout.close();
}

void main()
{
	cout << "Testing european options" << endl;
	testEuropeanOption();
}