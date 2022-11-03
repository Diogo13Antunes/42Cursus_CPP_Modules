/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:19:36 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/02 15:18:42 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

# define MAX_AMMOUT_CONTACTS	8

class PhoneBook
{
	private:
		Contact	contacts[MAX_AMMOUT_CONTACTS];
		int		oldestContact;
		int		nbrContact;

	public:

		PhoneBook();

		void	addContact();

		// Init PhoneBook
		void	initPhoneBook();
};
