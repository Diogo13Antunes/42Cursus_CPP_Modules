#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
bool	easyfind(const T &intContainer, int find)
{
	typename T::const_iterator	position;

	position = std::find(intContainer.begin(), intContainer.end(), find);
	if (position == intContainer.end())
		return (false);
	return (true);
}
