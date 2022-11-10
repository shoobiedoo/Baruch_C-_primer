#include <list>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
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
	cout << "Printing the first element of the doubleList : " << doubleList.front() << endl;//using the front function
	cout << "Printing the last element of the doubleList : " << doubleList.back() << endl;//using the back function
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
}
void vector_grow_testing() {
	vector<double> doubleVector;
	cout << "monitoring the growth rate of a dummy vector of size 50 and how its capacity increases after certain intervals" << endl;
	cout << "vector_element vector_size vector_capacty" << endl;
	for (int i = 0; i < 50 ; i++) {
		doubleVector.push_back(i+1);
		cout << doubleVector[i] << " " << doubleVector.size() << " " << doubleVector.capacity() << endl;
		// in this you can see the capacity increases after a certain interval ; thus signifying that our array is growing
	}
}
void map_testing() {
	map<string, double> mp;//mapping string to double
	mp["adhoc"] = 1.3;//explicit assigning values
	mp["tech debt"] = 3.4;
	mp["storypoint"] = -32.444;
	cout << "Printing map elements"<<endl;
	cout << "key : adhoc   value : " << mp["adhoc"]<<endl;
	cout << "key : tech debt   value : " << mp["tech debt"]<<endl;
	cout << "key : storypoint   value : " << mp["storypoint"]<<endl;
}
int main() {

	list_testing();//function call to test the doubleList functionality
	vector_testing();//function call to test the vector functionality
	vector_grow_testing();//function call to test the vector growth functionality
	map_testing();// functionm call to test the map functionality
	return 0;
}