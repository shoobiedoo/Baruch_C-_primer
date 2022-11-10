// StringConversions.cpp
//
// Handy string functions
//
// DD 205-12-3 kick-off
//
// (C) Datasim Education BV 2006
//

#ifndef StringConversions_CPP
#define StringConversions_CPP

#include <vector>
#include "UtilitiesDJD/BitsAndPieces/StringConversions.hpp"

// Simple and useful string converters
std::string getString(long j)
{
	char str[200];
	sprintf_s(str, "%d", j);
	std::string result(str);
	return result;
}

std::string getString(int j)
{
	char str[200];
	sprintf_s(str, "%d", j);
	std::string result(str);
	return result;
}
std::string getString(size_t j)
{
	char str[200];
	sprintf_s(str, "%d", j);
	std::string result(str);
	return result;
}

std::string getString(double d)
{
	char str[200];
	sprintf_s(str, "%f", d);
	std::string result(str);
	return result;
}

std::list<std::string> convertToString(const std::vector<double>& arr)
{

	std::list<std::string> result;

	for (std::vector<double>::const_iterator i = arr.begin(); i < arr.end(); ++i)
	{
		result.push_back(getString(*i));
	}
	return result;
}

#endif