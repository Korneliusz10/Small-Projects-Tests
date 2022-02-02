#pragma once
#include <string>
#include <algorithm>
class Delegate
{
public:
	Delegate(void (*nptr)(std::string), std::string );
	void operator()() { ptr(value); };
private :
	std::string value;
	void (*ptr)(std::string);
};

