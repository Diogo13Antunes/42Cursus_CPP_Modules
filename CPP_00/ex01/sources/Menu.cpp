/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:25:20 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/02 12:27:19 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Menu.hpp"

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
}

void	Menu::executeOption()
{
	if (option == OPTION_EXIT)
		exitPhoneBook();
	else if (option == OPTION_ADD)
		addContact();
	else if (option == OPTION_SEARCH)
		searchContact();
}
