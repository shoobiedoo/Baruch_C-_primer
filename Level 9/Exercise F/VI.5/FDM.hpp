// FDM.cpp
//
// FDM scheme for 1 factor Black Scholes equation. For the
// moment we assume explicit Euler.
//
// The responsibility of this class is to 
// (C) Datasim Education BV 2005
//
//

#ifndef FDM_CPP
#define FDM_CPP

#include "ParabolicPDE.hpp"
#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/VectorsAndMatrices/ArrayMechanisms.cpp"

#include <iostream>
using namespace std;



using namespace ParabolicIBVP;

class FDM
{
public:
		// Solver solver;

	//	Vector<double, long> A, B, C;	// LHS coefficients at level n+1
		std::vector<double> a, bb, c;	// LHS coefficients at level n
		std::vector<double> RHS;		// Inhomogeneous term
		
		std::vector<double> vecOld; // Sol at n
		std::vector<double> vecNew; // Sol at n+1

		FDM()
		{

		}

		void initIC(const std::vector<double>& xarr)
		{ // Initialise the solutin at time zero. This occurs only 
		  // at the interior mesh points of xarr (and there are J-1 
		  // of them).
		  

			vecOld = std::vector<double>(xarr.size());

			// Initialise at the boundaries
			vecOld[0] = BCL(0.0);
			vecOld[vecOld.size()-1] = BCR(0.0);

			// Now initialise values in interior of interval using
			// the initial function 'IC' from the PDE
			for (unsigned int j = 1; j < xarr.size()-1; j++)
			{
				vecOld[j] = IC(xarr[j]);
			}

			//print(vecOld);

			vecNew = vecOld; // V2 optimise
		
		}

		const std::vector<double>& current() const
		{
			return vecNew;
		}

		void calculateCoefficients(const std::vector<double>& xarr, double tprev, double tnow)
		{ // Calculate the coefficients for the solver

			// Explicit method
		//	A = Vector<double, long> (xarr.Size(), xarr.MinIndex(), 0.0);
		//	C = A;
		//	B = Vector<double, long> (xarr.Size(), xarr.MinIndex(), 1.0);

			a = std::vector<double> (xarr.size()-2);
			bb = std::vector<double> (xarr.size()-2);
			c = std::vector<double> (xarr.size()-2);
			RHS = std::vector<double> (xarr.size()-2);

			double tmp1, tmp2;
			double k = tnow - tprev;
			double h = xarr[1] - xarr[0];

			for (unsigned int j = 1; j < xarr.size()-1; j++)
			{

				tmp1 = k * ((sigma)(xarr[j], tprev)/(h*h));
				tmp2 = k * (((mu)(xarr[j], tprev)* 0.5)/h);
	
				a[j-1] = tmp1 - tmp2;
				bb[j-1] = 1.0 - (2.0 * tmp1) + (k * (b)(xarr[j], tprev));
				c[j-1] = tmp1 + tmp2;
				RHS[j-1] = k * f(xarr[j], tprev);
			}

		}

		void solve (double tnow)
		{
			// Explicit method

			vecNew[0] = BCL(tnow);
			vecNew[vecNew.size()-1] = BCR(tnow);

			for (unsigned int i = 1; i < vecNew.size()-1; i++)
			{
				vecNew[i] = (a[i-1] * vecOld[i-1])
									+ (bb[i-1] * vecOld[i])
									+ (c[i-1] * vecOld[i+1]) - RHS[i-1];
			}
			vecOld = vecNew; // Not the most efficient, V2 can optimise it
	
		}

};

#endif
