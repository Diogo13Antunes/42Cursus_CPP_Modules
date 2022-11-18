#include "Harl.hpp"

static void	sendMSG(std::string msg);

Harl::Harl(void)
{
	list[0].complain = COMPLAIN_DEBUG;
	list[0].act = &Harl::debug;
	list[1].complain = COMPLAIN_INFO;
	list[1].act = &Harl::info;
	list[2].complain = COMPLAIN_WARNING;
	list[2].act = &Harl::warning;
	list[3].complain = COMPLAIN_ERROR;
	list[3].act = &Harl::error;
}

Harl::~Harl()
{

}

void    Harl::debug(void)
{
	sendMSG("[ DEBUG ]");
	sendMSG("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!");
}

void    Harl::info(void)
{
	sendMSG("[ INFO ]");
	sendMSG("I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!");
}

void    Harl::warning(void)
{
	sendMSG("[ WARNING ]");
	sendMSG("I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.");
}

void    Harl::error(void)
{
	sendMSG("[ ERROR ]");
	sendMSG("This is unacceptable! I want to speak to the manager now.");
}

void    Harl::complain(std::string level)
{
	switch (getLevel(level))
	{
		case  0:
			printBefores(0);
			break;
		case  1:
			printBefores(1);
			break;
		case  2:
			printBefores(2);
			break;
		case  3:
			printBefores(3);
			break;
		default:
			sendMSG("[ Probably complaining about insignificant problems ]");
			break;
	}
}

int	Harl::getLevel(std::string level)
{
	int i = 0;
	for (i = 0; i < NBR_COMPLAINS; i++)
	{
		if (!level.compare(list[i].complain))
			break ;
	}
	return (i);
}

void     Harl::printBefores(int index)
{
	int i;

	for (i = index; i < NBR_COMPLAINS; i++)
	{
		(this->*list[i].act)();
		if (index > 0)
			std::cout << std::endl;
	}
}

static void	sendMSG(std::string msg)
{
	std::cout << msg << std::endl;
}
