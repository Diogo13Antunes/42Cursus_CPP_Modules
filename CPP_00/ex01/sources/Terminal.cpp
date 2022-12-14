/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Terminal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:55:35 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/08 10:50:15 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Terminal.hpp"

void	Terminal::write(std::string msg)
{
	std::cout << msg;
}

void	Terminal::clean()
{
	std::cout << "\x1B[2J\x1B[H";
}

std::string	Terminal::read(std::string msg)
{
	std::string	input;

	Terminal::write(msg);
	std::getline(std::cin >> std::ws, input);
	return (input);
}

void	Terminal::wait_enter()
{
	Terminal::write("Press ENTER to continue");
	std::getchar();
	Terminal::clean();
}
