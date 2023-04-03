#pragma once

#include <stack>
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
};
