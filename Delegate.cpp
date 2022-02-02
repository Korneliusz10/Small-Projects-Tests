#include "Delegate.h"

Delegate::Delegate(void (*nptr)(std::string), std::string nvalue) {
	ptr = nptr;
	value = nvalue;
};
