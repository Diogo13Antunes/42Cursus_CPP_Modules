#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>

#define DIV	32

class PmergeMe
{
	public:
		void	setArguments(char **args);
		
		void	printVectorData(void);
		void	printDequeData(void);

		void	sort(void);

		void	printTimes(void);

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

		clock_t				_beginSetArguments;
		clock_t				_endSetArguments;
		double				_durationSetArguments;

		clock_t				_beginVector;
		clock_t				_endVector;
		double				_durationVector;

		clock_t				_beginDeque;
		clock_t				_endDeque;
		double				_durationDeque;

		void				setDequeData(void);
		void				setVectorData(void);
};
