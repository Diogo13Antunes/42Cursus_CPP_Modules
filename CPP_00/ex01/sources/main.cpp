/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:55:54 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/02 11:15:16 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Menu.hpp"
#include "../includes/Contact.hpp"

int main(void)
{
	Menu mainMenu;

	mainMenu.printInitialMenu();
	mainMenu.setOption();
	return (0);
}
