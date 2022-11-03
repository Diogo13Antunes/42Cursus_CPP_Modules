/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:25:20 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/03 17:28:31 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Menu.hpp"

Menu::Menu():
	exitStatus(1)
{}

void	Menu::printInitialMenu(void) const
{
	std::cout << "------------- Phone Book -------------" << std::endl;
	std::cout << "ADD -> Adds a new contact" << std::endl;
	std::cout << "SEARCH -> Searchs a specific contact" << std::endl;
	std::cout << "EXIT -> Exit phone book" << std::endl;
	std::cout << std::endl;
	std::cout << "Option: ";
}

void	Menu::setOption(void)
{
	std::string	temp_option;

	std::getline(std::cin, temp_option);
	if (temp_option.compare("ADD") == 0 || temp_option.compare("add") == 0)
		option = OPTION_ADD;
	else if (temp_option.compare("EXIT") == 0 || temp_option.compare("exit") == 0)
		option = OPTION_EXIT;
	else if (temp_option.compare("SEARCH") == 0 || temp_option.compare("search") == 0)
		option = OPTION_SEARCH;
	else
		return ;
}

void	Menu::executeOption()
{
	if (option == OPTION_EXIT)
		exitStatus = 0;
	else if (option == OPTION_ADD)
		book.createContact();
	else if (option == OPTION_SEARCH)
		book.searchContact();
}

int	Menu::getExitStatus() const
{
	return (exitStatus);
}
