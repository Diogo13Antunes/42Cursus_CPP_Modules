#pragma once

#include <iostream>

template <typename T>
void	iter(T *array, size_t arrayLength, void (*func)(const T&))
{
	for (size_t i = 0; i < arrayLength; i++)
		func(array[i]);
}
