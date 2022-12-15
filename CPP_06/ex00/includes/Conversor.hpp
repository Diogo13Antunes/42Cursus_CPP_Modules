#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>

class Conversor
{
	public:
		Conversor(void);
		~Conversor(void);

		void	convert(std::string value);

	private:

		Conversor(const Conversor &src);
		Conversor &operator=(const Conversor &src);

		bool	checkInput(std::string value) const;

		bool	isEdgeCase(std::string value);

		void	edgeCasesConvertion(std::string value);
		void	charConvertion(std::string value);
		void	intConvertion(std::string value);
		void	floatConvertion(std::string value);
		void	doubleConvertion(std::string value);
};
