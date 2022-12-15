#include <Data.hpp>

Data::Data(void): _nbr(0)
{
	//Default Data Constructor
}

Data::Data(const int nbr): _nbr(nbr)
{
	//Data nbr Constructor
}

Data::Data(const Data &src)
{
	//Data Copy Constructor
	*this = src;
}

Data::~Data(void)
{
	//Default Data Destructor
}

Data &Data::operator=(const Data &src)
{
	//Data Copy Assignment Operator
	this->_nbr = src._nbr;
	return (*this);
}

void	Data::setNbr(const int nbr)
{
	this->_nbr = nbr;
}

int	Data::getNbr(void) const
{
	return (this->_nbr);
}
