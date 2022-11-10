
#ifndef FUNCTOR_CPP
#define FUNCTOR_CPP
#include "Functor.h"
template <typename T>
Functor<T>::Functor()
{
	threshold = 0;
	cout << "Default constructor";
}

template <typename T>
Functor<T>::Functor(T& thresh)
{
	cout << "Parametrized constructor setting threshold to " << thresh << endl;
	threshold = thresh;
}
template <typename T>
Functor<T>::~Functor()
{
	cout << "Functor destructor" << endl;
}

template<typename T>
Functor<T>::Functor(const Functor& f)
{
	threshold = f.threshold;
	cout << "Copy constructor" << endl;
}

template<typename T>
bool Functor<T>::operator()(const T& num) const
{
	return num < threshold;
}

#endif