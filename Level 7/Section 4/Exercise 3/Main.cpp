#include <iostream>
#include <functional>			// For function objects
#include <algorithm>
#include <vector>
#include "Functor.h"
using namespace std;
//global comparator function
bool comparator(const double num)
{
	double threshold = 8.1;
	return  (num < threshold);
}

int main() {
	
	vector <double> vect = { 0,1,2.2,3,4.1,4,4.3,5.5,6,7,8,9 };
	cout << "Printing the array in use " << endl;
	for (auto v : vect) {
		cout << v << " ";
	}
	cout << endl;
	vector <double>::iterator it_start=vect.begin();
	vector <double>::iterator it_end=vect.end();
	int number = count_if(it_start, it_end, comparator);//calling the count_if method
	cout << "The count_if value for threshold 8.1 is" << number << endl;
	double threshold = 4.4;// user defined threshold
	Functor<double> f(threshold);//defining the function object
	int number2 = count_if(it_start, it_end, f);//passing it to the Functor constructor and simultaneously overloading it 
	// we can also do it one go like  count_if(it_start, it_end,Functor<double>(threshold)) this triggers both the () and the constructor
	cout << "The count_if value for threshold "<<threshold<<" is " << number2 << endl;
	return 0;
}