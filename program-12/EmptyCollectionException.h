#pragma once
#include <stdexcept>			// include built-in exception classes

class EmptyCollectionException : public std::runtime_error
{
public:
	EmptyCollectionException();
};

