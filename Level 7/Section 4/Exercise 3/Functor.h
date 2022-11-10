#ifndef FUNCTOR_H
#define FUNCTOR_H
#include <iostream>
using namespace std;
template<typename T>
class Functor//our function object 
{
private:
	T threshold;
public:
	Functor();//default constructor
	Functor(T& threshold);//parametrized constructor
	~Functor();//destructor
	Functor(const Functor& f);//copy constructor
	//() operator overloading
	bool operator () (const T & num) const;
};
#ifndef FUNCTOR_CPP // Same as in the source file 
#include "Functor.cpp"
#endif
#endif

