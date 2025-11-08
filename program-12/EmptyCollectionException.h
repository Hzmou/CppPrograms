#pragma once
#include <stdexcept>			// include built-in exception classes

class EmptyCollectionException : public std::runtime_error
{
public:
	// Constructor that accepts a string message
    EmptyCollectionException(const std::string& message) 
        : std::runtime_error(message) {}
};

