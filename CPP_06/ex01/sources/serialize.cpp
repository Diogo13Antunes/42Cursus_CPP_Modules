#include <Data.hpp>

uintptr_t	serialize(Data *ptr)
{
	uintptr_t	newptr;

	newptr = reinterpret_cast<uintptr_t>(ptr);
	return (newptr);
}

