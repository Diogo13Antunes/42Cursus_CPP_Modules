/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:19:36 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/07 17:50:39 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Contact.hpp"
# include "Terminal.hpp"
# include <iostream>
# include <string>
# include <cstdlib>

# define MAX_AMMOUT_CONTACTS	8

class PhoneBook
{
	private:
		Contact	contacts[MAX_AMMOUT_CONTACTS];
		int		oldestContact;
		int		nbrContact;

	public:
		PhoneBook()
		{
			oldestContact = 0;
			nbrContact = 0;
		}
		~PhoneBook() {};
		
		void	createContact();
		void	searchContact() const;
};
