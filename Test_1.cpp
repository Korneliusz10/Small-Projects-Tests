#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Delegate.h"

// Korneliusz Bedynski B7024225 Test 2

	// Question 1 & 2
struct display
{
	display() : value(0) {}
	void operator()(std::string n) { ++value; std::cout << n << std::endl ; };
	int value;
};
	// Question 3
struct FunctorBase 
{
	virtual float operator()(float x,float y) = 0;
};

struct subtract_functor : FunctorBase
{
	float operator()(float x, float y) override { return x - y; };
};

struct add_functor : FunctorBase
{
	float operator()(float x, float y) override { return x + y; };
};

struct process 
{
	float operator()(FunctorBase* b_ptr,float x, float y){ return b_ptr->operator()(x,y);};
};

	// for making new lines
void newline() {
	std::cout << std::endl;
}

void prin(int x) { std::cout << x << std::endl; };

	// Question 4
void dString(std::string x)
{
	std::cout << x;
};

void dRString(std::string x)
{
	std::reverse(x.begin(),x.end());
	std::cout << x;
};

void Pass_Delegate(Delegate n) {
	std::cout << "I passed a Delegate";
	n();
}

int main()
{
	// QUESTION 1
	std::vector<std::string> v;
	v.push_back("Apple");v.push_back("Orange");v.push_back("Banana");v.push_back("Grape");v.push_back("Pear");
	display d;
	d = std::for_each(v.begin(), v.end(), d); // the d = is for question 2 to work
	newline();

	// QUESTION 2
	prin(d.value); // this uses question one functor to count as the string in question one has 5 elements
	newline();

	// QUESTION 3
	subtract_functor s; add_functor a; process p;
	std::cout << "Addition : " << a(2,1);
	newline();
	std::cout << "Subtraction : " << s(2,1);
	newline();
	// QUESTION 3 Part 2
	FunctorBase* ptr; // we create the pointer
	ptr = &s; // sett it to s

	std::cout << p(ptr,10,2); // run the code with the pointer pointing to the derived class 

	newline();
	ptr = &a; // retarget the pointer

	std::cout << p(ptr, 10, 2); // and do the same
	newline();
	// QUESTION 4 
	Delegate test(&dString, "test"); // normal display
	test();
	newline();
	Delegate test2(&dRString, "test");; // Reverse display
	test2();
	newline();

	Pass_Delegate(test);

}