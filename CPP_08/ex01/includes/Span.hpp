#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	public:

		void	addNumber(int nbr);
		void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		Span &operator=(const Span &src);
		Span(const Span &src);
		Span(unsigned int N);
		Span(void);
		~Span(void);

	private:
		unsigned int		_nbrIntegers;
		std::vector<int>	_integers;
};
