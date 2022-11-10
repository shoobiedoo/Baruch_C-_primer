// mesher.cpp
//
// A simple mesher on a 1d domain. We divide
// an interval into J+1 mesh points, J-1 of which
// are internal mesh points.
//

#include <vector>

class Mesher
{
public:
		double a, b;	// In space

		Mesher()
		{
			a =0.0; b = 1.0;
		}

		Mesher (double A, double B)
		{ // Describe the domain of integration

			a = A;
			b = B;
		}

		std::vector<double> xarr(int J)
		{
			// NB Full array (includes end points)

			double h = (b - a) / double (J);
			
			int size = J+1;
			int start = 1;

			std::vector<double> result(size, start);
			result[0] = a;

			for (unsigned int j = 1; j < result.size(); j++)
			{
				result[j] = result[j-1] + h;
			}

			return result;
		}

		std::vector<double> Xarr(int J)
		{ // Return as an STL vector

			// NB Full array (includes end points)

			double h = (b - a) / double (J);
			
			int size = J+1;
			int start = 1;

			std::vector<double> result(size, start);
			result[0] = a;

			for (unsigned int j = 1; j < result.size(); j++)
			{
				result[j] = result[j-1] + h;
			}

			return result;
		}

};
