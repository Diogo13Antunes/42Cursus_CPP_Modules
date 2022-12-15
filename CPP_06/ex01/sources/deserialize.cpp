#include <Data.hpp>

Data *deserialize(uintptr_t raw)
{
	Data *newData;

	newData = reinterpret_cast<Data *>(raw);
	return (newData);
}
