/*
* Test program to check how random works and how we can define a range for the same for both continuous and discrete numbers
* also defining the seed 
*/

#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <ctime> // std::time
#include <map>	//map to store the statistics
using namespace std;
int main()
{
	// Get random number generator
	boost::mt19937 myRng;
	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));
	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);

	map<int, long> statistics; // Structure to hold outcome + frequencies
	int outcome; // Current outcome
	int numberOfTrials = 0;
	//initializing the statistics map to 0 for each of the outcomes
	for (int i = 1; i <= 6; i++) {
		statistics[i] = 0;
	}
	cout << "How many trials ?" << endl;
	cin >> numberOfTrials; //taking input for the number of trials 
	int n = numberOfTrials; //making a copy of the number of trials so that while calculating percentage we don't divide by zero
	while (n--) {
		outcome = six(myRng);
		statistics[outcome]++;//incrementing the outcome frequency by one 
	}
	for (auto s : statistics) {
		double percent = ((double) s.second / (double)numberOfTrials) * 100.0;//calculating the percentage for each of the outcomes
		cout << "Trial " << s.first << " has "<<percent<<"% outcomes" << endl;
	}
	return 0;

}