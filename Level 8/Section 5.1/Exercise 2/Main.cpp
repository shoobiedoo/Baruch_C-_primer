/*
Program to test how boost tuples work and how we can use them to combine different classes instead of creating a parent class
and using diff inheritance techniques
*/
#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_io.hpp"
#include <iostream>
using namespace std;
using boost::tuple;
typedef boost::tuple<string, int, double> Person;
void Print(Person p) {
	cout << "P_name age length : " << endl;
	cout << get<0>(p) << " " << get<1>(p) << " " << get<2>(p) << endl;//using the get function to fetch individual attributes
}
int main() {
	
	Person p1("p1_name", 12, 7.3);
	//The sequence should be the same as mentioned in the typedef while declaring the datatypes
	//for example something like Person p2(2,"p2_name",5); will throw a compiler error
	//but the following works:
	Person p2("p2_name", 5 ,2);
	cout << "Before incrementing the age of P1 :" << endl;
	Print(p1);//calling the print function and passing the tuple p1
	get<1>(p1)++;//incrementing the age by one as we ARE INCREMENTING the reference not the value
	cout << "After incrementing the age of P1 by one :" << endl;
	Print(p1);//calling the print function again post incrementing
	cout << "Also Printing p2 :" << endl;
	Print(p2);
	return 0;
}