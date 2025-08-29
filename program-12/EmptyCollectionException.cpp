#include "EmptyCollectionException.h"

EmptyCollectionException::EmptyCollectionException() :
	std::runtime_error {"Collection is empty"}
{
}