#include <Span.hpp>

Span::Span(void): _nbrIntegers(0)
{
	//Default Span Constructor
}

Span::Span(unsigned int N): _nbrIntegers(N)
{
	//Amount of Integers Constructor
}

Span::Span(const Span &src)
{
	//Span Copy Constructor
	*this = src;
}

Span::~Span(void)
{
	//Default Span Destructor
}

Span &Span::operator=(const Span &src)
{
	//Span Copy Assignment Operator
	this->_nbrIntegers = src._nbrIntegers;
	this->_integers = src._integers;
	return (*this);
}

void	Span::addNumber(int nbr)
{
	if (this->_integers.size() == this->_nbrIntegers)
		throw std::exception();
	this->_integers.push_back(nbr);
}

unsigned int Span::shortestSpan(void)
{
	std::vector<int>::iterator	it;
	std::vector<int>			temp;
	unsigned int				result;
	unsigned int				tp;

	temp = this->_integers;
	if (temp.size() < 2)
		throw std::exception();
	std::sort(temp.begin(), temp.end());
	for (it = temp.begin(); it != temp.end(); it++)
	{
		if (it == temp.begin())
			result = static_cast<unsigned int>(*it - *(it + 1));
		else
		{
			tp = static_cast<unsigned int>(*it - *(it - 1));
			if (tp < result)
				result = tp;
		}
	}
	return (result);
}

unsigned int Span::longestSpan(void)
{
	std::vector<int>			temp;
	std::vector<int>::iterator	max;
	std::vector<int>::iterator	min;
	unsigned int				result;

	temp = this->_integers;
	if (temp.size() < 2)
		throw std::exception();
	max = std::max_element(temp.begin(), temp.end());
	min = std::min_element(temp.begin(), temp.end());
	result = static_cast<unsigned int>(*max - *min);
	return (result);
}
