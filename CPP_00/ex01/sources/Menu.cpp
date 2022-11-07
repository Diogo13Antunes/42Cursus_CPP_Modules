/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:25:20 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/07 14:58:07 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Menu.hpp>

Menu::Menu():
	exitStatus(1)
{}

std::string	Menu::initial(void) const
{
	std::string os;
	
	// Terminal::clean();
	os += "------------- Phone Book -------------\n";
	os += "ADD -> Adds a new contact\n";
	os += "SEARCH -> Searchs a specific contact\n";
	os += "EXIT -> Exit phone book\n\n";
	os += "Option: ";
	return (os);
}

void	Menu::setOption(void)
{
	std::string	temp_option;

	temp_option = Terminal::read("");
	if (temp_option.compare("ADD") == 0 || temp_option.compare("add") == 0)
		addContact();
	else if (temp_option.compare("EXIT") == 0 || temp_option.compare("exit") == 0)
		exit();
	else if (temp_option.compare("SEARCH") == 0 || temp_option.compare("search") == 0)
		searchContact();
	else
		Terminal::clean();
}

void	Menu::exit()
{
	exitStatus = 0;
}

void	Menu::addContact()
{
	Terminal::clean();
	book.createContact();
}

void	Menu::searchContact()
{
	Terminal::clean();
	book.searchContact();
}

int	Menu::run() const
{
	return (exitStatus);
}
