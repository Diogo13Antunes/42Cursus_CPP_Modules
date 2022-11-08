/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:02:52 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/08 10:58:13 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

void	Contact::setFirstName()
{
	firstName = Terminal::read("Fisrt Name: ");
	if (!check_user_input(firstName))
	{
		Terminal::write("Invalid First Name\n");
		setFirstName();
	}
}

void	Contact::setLastName()
{
	lastName = Terminal::read("Last Name: ");
	if (!check_user_input(lastName))
	{
		Terminal::write("Invalid Last Name\n");
		setLastName();
	}
}

void	Contact::setNickname()
{
	nickname = Terminal::read("Nickname: ");
	if (!check_user_input(nickname))
	{
		Terminal::write("Invalid Nickname\n");
		setNickname();
	}
}

void	Contact::setPhoneNumber()
{
	phoneNumber = Terminal::read("Phone Number: ");
	if (!check_user_input(phoneNumber))
	{
		Terminal::write("Invalid Phone Number\n");
		setPhoneNumber();
	}
}

void	Contact::setSecret()
{
	secret = Terminal::read("Secret: ");
	if (!check_user_input(secret))
	{
		Terminal::write("Invalid Secret\n");
		setSecret();
	}
}

std::string Contact::getFisrtName() const
{
	return (firstName);
}

std::string Contact::getLastName() const
{
	return (lastName);
}

std::string Contact::getNickname() const
{
	return (nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (phoneNumber);
}

std::string Contact::getSecret() const
{
	return (secret);
}
