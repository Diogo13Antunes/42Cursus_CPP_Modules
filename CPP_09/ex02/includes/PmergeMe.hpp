#pragma once

class PmergeMe
{
	public:
		PmergeMe &operator=(const PmergeMe &src);
		PmergeMe(const PmergeMe &src);
		PmergeMe(void);
		~PmergeMe(void);
};
