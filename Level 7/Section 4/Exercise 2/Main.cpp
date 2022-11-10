#include <list>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

template <class T> double Sum(const T& t)
{  // A generic sum function for vectors and lists
	double ans = 0;
	// We must use a const iterator here, otherwise we get a compiler error.
	typename T::const_iterator it_start = t.begin();
	typename T::const_iterator it_end = t.end();
	while (it_start != it_end) {
		ans += *it_start;
		it_start++;
	}
	return ans;
}
//template function for vector and list  iterators
template <typename T>
double Sum(typename T::const_iterator it_start, typename T::const_iterator it_end) { 
	double sum = 0;
	while (it_start != it_end) {
		sum += *it_start;
		it_start++;
	}
	return sum;
}
//template function for map container without any iterator
template <typename K, typename V>
double Sum(const std::map<K, V>& temp) {
	double sum = 0.0;

	// Loop through all elements of the container using an iterator.
	typename map< K, V>::const_iterator it;
	for (it = temp.begin(); it != temp.end(); it++)
	{
		sum = sum + (it->second);
	}
	return sum;
}

//template function for specific map<string,double> for map iterators
template <>
double Sum<map<string, double>>(map<string, double>::const_iterator start, map<string, double>::const_iterator end) { 
	// Initialise double to hold the sum.
	double sum = 0.0;

	// Loop through all elements of the container using an iterator.
	typename map< string , double >::const_iterator it;
	for (it = start; it != end; it++)
	{
		sum = sum + (it->second);
	}

	return sum;
}
void list_testing() {
	cout << "Double List Testing" << endl;
	list <double> doubleList;//declaring a double list
	cout << "please enter the size of the list" << endl;
	int size;
	cin >> size;
	cout << "please enter the double elements" << endl;
	for (int i = 0; i < size; i++) {
		double temp;
		cin >> temp;
		doubleList.push_back(temp);//inserting elements into the list
	}
	cout << "Sum of all the elements of the list " << Sum(doubleList) << endl;
	//special case handlinhg if the user inputs the size of 1 or 0 and there is no second last and second element
	if (size == 1 || size == 0) {
		cout << "Sum of all the elements of the list except the first one and the last one " << 0 << endl;

	}
	else {
		list<double>::const_iterator second_it = ++doubleList.begin();
		list<double>::const_iterator second_last_it = --doubleList.end();
		cout << "Sum of all the elements of the list except the first one and the last one " << Sum<list<double>>(second_it, second_last_it) << endl;
	}
}

void vector_testing() {
	cout << "Double Vector Testing" << endl;
	vector <double> doubleVector;//declaring a double vector
	cout << "please enter the size of the vector" << endl;
	int size;
	cin >> size;
	cout << "please enter the double elements" << endl;
	for (int i = 0; i < size; i++) {
		double temp;
		cin >> temp;
		doubleVector.push_back(temp);//inserting elements into the vector

	}
	cout << "Printing all the vector elements sequentially" << endl;
	for (int i = 0; i < doubleVector.size(); i++) {
		cout << doubleVector[i] << endl;
	}
	
	cout << "Sum of all the elements of the vector" << Sum(doubleVector) << endl;
	double temp_ans = 0;
	//special case handlinhg if the user inputs the size of 1 or 0 and there is no second last and second element
	if (size == 1 || size == 0) {
		cout << "Sum of all the elements of the vector except the first one and the last one " << 0 << endl;
	}
	else {
		vector<double>::const_iterator second_it = ++doubleVector.begin();
		vector<double>::const_iterator second_last_it = --doubleVector.end();
		cout << "Sum of all the elements of the vector except the first one and the last one " << Sum<vector<double>>(second_it, second_last_it) << endl;
	}
}
void map_testing() {
	map<string, double> mp;//mapping string to double
	mp["adhoc"] = 1.3;//explicit assigning values
	mp["tech debt"] = 3.4;
	mp["storypoint"] = -32.444;
	cout << "Printing map elements" << endl;
	for (auto k : mp) {
		cout << k.first << " " << k.second << endl;
	}
	map<string, double>::const_iterator second_it = ++mp.begin();
	map<string, double>::const_iterator second_last_it = --mp.end();
	cout << "Sum of all the elements of the map" << Sum(mp) << endl;
	cout << "Sum of all the elements of the vector except the first one and the last one " << Sum<map<string,double>>(second_it, second_last_it) << endl;

}


int main() {
	
	list_testing();//function call to test the doubleList functionality
	vector_testing();//function call to test the vector functionality
	map_testing();// functionm call to test the map functionality
	return 0;
}