/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:25:20 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/02 11:26:24 by dcandeia         ###   ########.fr       */
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
	// std::cout << "[" + temp_option + "]" << std::endl;
	
}