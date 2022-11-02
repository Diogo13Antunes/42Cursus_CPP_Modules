/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:02:52 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/02 10:46:20 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

void	Contact::setFirstName()
{
	std::cout << "Fisrt Name: ";
	std::getline(std::cin, first_name);
	if (!check_user_input(first_name))
	{
		std::cout << "Invalid Fisrt Name" << std::endl;
		setFirstName();
	}
}

void	Contact::setLastName()
{
	std::cout << "Last Name: ";
	std::getline(std::cin, last_name);
	if (!check_user_input(last_name))
	{
		std::cout << "Invalid Last Name" << std::endl;
		setLastName();
	}
}

void	Contact::setNickname()
{
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	if (!check_user_input(nickname))
	{
		std::cout << "Invalid Nickname" << std::endl;
		setNickname();
	}
}

void	Contact::setPhoneNumber()
{
	std::cout << "Phone Number: ";
	std::getline(std::cin, phone_number);
	if (!check_user_input(phone_number))
	{
		std::cout << "Invalid Phone Number" << std::endl;
		setPhoneNumber();
	}
}

void	Contact::setSecret()
{
	std::cout << "Phone Number: ";
	std::getline(std::cin, secret);
	if (!check_user_input(secret))
	{
		std::cout << "Invalid Secret" << std::endl;
		setSecret();
	}
}

std::string Contact::getFisrtName() const
{
	return (first_name);
}

std::string Contact::getLastName() const
{
	return (last_name);
}

std::string Contact::getNickname() const
{
	return (nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (phone_number);
}

std::string Contact::getSecret() const
{
	return (secret);
}
