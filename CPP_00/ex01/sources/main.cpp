/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:55:54 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/04 13:23:31 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Menu.hpp"
#include "../includes/Contact.hpp"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	Menu		menu;

	while (menu.run())
	{
		Terminal::write(menu.initial());
		menu.setOption();
	}
	return (0);
}
