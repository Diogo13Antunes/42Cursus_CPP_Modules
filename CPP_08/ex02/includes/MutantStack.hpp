#pragma once

#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack();
		MutantStack(const MutantStack& src);
		~MutantStack();
		MutantStack& operator=(const MutantStack& src);
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;		
};

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& src): std::stack<T>(src) {}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& src)
{
	std::stack<T>::operator=(src);
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>		
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template<typename T>		
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}
