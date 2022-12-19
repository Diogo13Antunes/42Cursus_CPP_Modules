#pragma once

#include <iostream>

template <typename T>
class Array
{
	public:

		unsigned int	size(void) {return (this->_arrayLen);}

		/* write to the class */
		T &operator[](unsigned int index)
		{
			if (index < this->_arrayLen)
				return (this->_array[index]);
			else
				throw std::exception();
		}
		/* read from the class */
		const T &operator[](unsigned int index) const
		{
			if (index < this->_arrayLen)
				return (this->_array[index]);
			else
				throw std::exception();
		}
		Array	&operator=(const Array &src)
		{
			delete []this->_array;
			this->_arrayLen = src._arrayLen;
			this->_array = new T[this->_arrayLen];
			for (unsigned int i = 0; i < src._arrayLen; i++)
				this->_array[i] = src._array[i];
			return (*this);
		}
		Array(const Array &src): _arrayLen(src._arrayLen), _array(new T[src._arrayLen])
		{
			for (unsigned int i = 0; i < src._arrayLen; i++)
				this->_array[i] = src._array[i];
		}
		Array(unsigned int n): _arrayLen(n), _array(new T[n]) {}
		Array(): _arrayLen(0), _array(new T[0]) {}
		~Array()
		{
			delete []this->_array;
		}

	private:
		unsigned int	_arrayLen;
		T				*_array;
};
