/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_checks.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:21:07 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/03 16:08:41 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include <stdio.h>

static int	is_only_white_charecters(std::string input);
static int	is_space(int character);

int	check_user_input(std::string input)
{
	if (input.empty())
		return (FALSE);
	if (is_only_white_charecters(input))
		return (FALSE);
	if (is_only_white_charecters(input))
		return (FALSE);
	std::cout << "Here" << std::endl;
	return (TRUE);
}

// Checks if the string only contais white charecters.
static int	is_only_white_charecters(std::string input)
{
	int	i = 0;
	int counter = 0;

	while (input[i])
	{
		if (is_space(input[i]))
			counter++;
		i++;
	}
	if (counter == (int)input.length())
		return (TRUE);
	return (FALSE);
}

static int	is_space(int character)
{
	char c;

	c = (char)character;
	switch (c)
	{
		case ' ':
			return (TRUE);
		case '\t':
			return (TRUE);
		case '\f':
			return (TRUE);
		case '\v':
			return (TRUE);
		case '\n':
			return (TRUE);
		case '\r':
			return (TRUE);
		default:
			return (FALSE);
	}
}
