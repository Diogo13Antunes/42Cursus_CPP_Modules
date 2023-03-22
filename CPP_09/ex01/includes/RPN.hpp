#pragma once

#include <list>
#include <iostream>
#include <string>
#include <sstream>

class RPN
{
	public:
		void	getData(const char *src);

		RPN &operator=(const RPN &src);
		RPN(const RPN &src);
		RPN(void);
		~RPN(void);
	
	private:
		std::list<std::string>	_data;
};
