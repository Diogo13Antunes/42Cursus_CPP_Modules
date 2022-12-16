#pragma once

#include <iostream>
#include <string>

template <typename T>
void	swap(T &x1, T &x2)
{
	T temp;

	temp = x1;
	x1 = x2;
	x2 = temp;
}

template <typename T>
T	max(T x1, T x2)
{
	if (x1 <= x2)
		return (x2);
	else
		return (x1);
}

template <typename T>
T	min(T x1, T x2)
{
	if (x1 >= x2)
		return (x2);
	else
		return (x1);
}
