/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:32:15 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/02 15:17:43 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_HPP
# define MENU_HPP

# include <string>
# include <iostream>

# include "../includes/Contact.hpp"
# include "../includes/PhoneBook.hpp"

# define OPTION_EXIT	0
# define OPTION_ADD		1
# define OPTION_SEARCH	2

# define WORD_EXIT		"EXIT"
# define WORD_ADD		"ADD"
# define WORD_SEARCH	"SEARCH"

class Menu
{
	private:
		int	option;
		PhoneBook book;

	public:

		// Setters
		void	setOption(void);

		// Executers
		void	executeOption();
		void	addContact();
		void	searchContact();
		void	exitPhoneBook();

		// Printers
		void	printInitialMenu(void) const;
};

#endif