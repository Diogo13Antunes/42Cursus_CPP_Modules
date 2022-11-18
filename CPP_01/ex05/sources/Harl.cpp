#include "Harl.hpp"

static void	sendMSG(std::string msg);

Harl::Harl(void)
{
	list[0].complain = COMPLAIN_DEBUG;
	list[0].act = &Harl::debug;
	list[1].complain = COMPLAIN_ERROR;
	list[1].act = &Harl::error;
	list[2].complain = COMPLAIN_INFO;
	list[2].act = &Harl::info;
	list[3].complain = COMPLAIN_WARNING;
	list[3].act = &Harl::warning;
}

Harl::~Harl()
{

}

void    Harl::debug(void)
{
	sendMSG("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!");
}

void    Harl::info(void)
{
	sendMSG("I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!");
}

void    Harl::warning(void)
{
	sendMSG("I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.");
}

void    Harl::error(void)
{
	sendMSG("This is unacceptable! I want to speak to the manager now.");
}

void    Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (list[i].complain == level)
		{
			(this->*list[i].act)();
			return ;
		}
	}
	sendMSG("No valid complain!");
}

static void	sendMSG(std::string msg)
{
	std::cout << msg << std::endl;
}
