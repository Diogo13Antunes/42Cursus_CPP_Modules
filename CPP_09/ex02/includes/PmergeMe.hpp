#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <sstream>

class PmergeMe
{
	public:
		void	setArguments(char **args);
		
		void	printVectorData(void);
		void	printDequeData(void);

		void	sort(void);

		PmergeMe &operator=(const PmergeMe &src);
		PmergeMe(const PmergeMe &src);
		PmergeMe(void);
		PmergeMe(char **args, int amountNbrs);
		~PmergeMe(void);
	
	private:
		char 				**_initialData;
		int					_initialDataSize;
		std::vector<int>	_vectorData;
		std::deque<int>		_dequeData;

		void	setDequeData(void);
		void	setVectorData(void);
};
