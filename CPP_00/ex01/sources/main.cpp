/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:55:54 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/03 12:58:39 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Menu.hpp"
#include "../includes/Contact.hpp"
#include <stdlib.h>

int main(void)
{
	Menu mainMenu;

	while (mainMenu.getExitStatus())
	{
		system("clear");
		mainMenu.printInitialMenu();
		mainMenu.setOption();
		mainMenu.executeOption();
	}
	return (0);
}
