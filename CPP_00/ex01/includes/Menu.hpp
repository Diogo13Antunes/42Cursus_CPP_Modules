/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:32:15 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/04 12:48:19 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

# include <Contact.hpp>
# include <PhoneBook.hpp>
# include <Terminal.hpp>


# define WORD_EXIT		"EXIT"
# define WORD_ADD		"ADD"
# define WORD_SEARCH	"SEARCH"

class Menu
{
	private:
		int			exitStatus;
		PhoneBook	book;
		Terminal	term;

	public:

		Menu();

		// Setters
		void	setOption(void);

		// Getters
		int		run() const;

		// Executers
		void	addContact();
		void	searchContact();
		void	exit();
		void	exitPhoneBook();

		// Printers
		std::string	initial(void) const;
};
