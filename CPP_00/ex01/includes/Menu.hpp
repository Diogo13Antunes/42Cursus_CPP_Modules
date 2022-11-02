/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:32:15 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/02 11:27:57 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_HPP
# define MENU_HPP

# include <string>
# include <iostream>

# define OPTION_EXIT	0
# define OPTION_ADD		1
# define OPTION_SEARCH	2


# define WORD_EXIT		"EXIT"
# define WORD_ADD		"ADD"
# define WORD_SEARCH	"SEARCH"

class Menu
{
	private:
		std::string	option;
	
	public:

		// Setters
		void	setOption(void);

		// Printers
		void	printInitialMenu(void) const;
};

#endif