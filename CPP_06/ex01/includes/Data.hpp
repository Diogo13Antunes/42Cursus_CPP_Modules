#pragma once

#include <stdint.h>

class Data
{
	public:

		void	setNbr(const int nbr);
		int		getNbr(void) const;

		Data &operator=(const Data &src);
		Data(const int nbr);
		Data(const Data &src);
		Data(void);
		~Data(void);

	private:
		int	_nbr;
};
