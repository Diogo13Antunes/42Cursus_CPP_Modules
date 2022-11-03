/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:20:50 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/03 15:01:26 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <string>
# include <iostream>

# define TRUE	1
# define FALSE	0

int	check_user_input(std::string input);

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	secret;

	public:

		// Class constructor
		Contact() {};
		
		// Class distructor
		~Contact() {};

		// Setters
		void		setFirstName(void);
		void		setLastName(void);
		void		setNickname(void);
		void		setPhoneNumber(void);
		void		setSecret(void);
		
		// Getters
		std::string	getFisrtName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getSecret() const;

		// Print info
};

#endif