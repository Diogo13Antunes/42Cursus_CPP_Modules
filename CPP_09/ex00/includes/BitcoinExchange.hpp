#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

class BitcoinExchange
{
	public:
		void	setDataBase(const char *dataBaseFileName);
		void	exchanger(char *fileName);

		BitcoinExchange &operator=(const BitcoinExchange &src);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange(void);
		~BitcoinExchange(void);

	private:
		void	makeExchange(std::string date, std::string value);

		std::string							dataBaseFileName;
		std::map<std::string, std::string>	dataBase;
};
