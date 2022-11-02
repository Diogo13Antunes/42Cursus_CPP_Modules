/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_checks.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:21:07 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/02 10:49:27 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

static int	is_only_white_charecters(std::string input);

int	check_user_input(std::string input)
{
	if (input.empty())
		return (FALSE);
	if (is_only_white_charecters(input))
		return (FALSE);
	return (TRUE);
}

// Checks if the string only contais white charecters.
static int	is_only_white_charecters(std::string input)
{
	int	i = 0;

	while (input[i])
	{
		if (!((input[i] >= 9 && input[i] <= 13) || input[i] == 13))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
