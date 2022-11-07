/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Terminal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:55:35 by dcandeia          #+#    #+#             */
/*   Updated: 2022/11/07 15:13:11 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include <iomanip>
# include <cstdio>

class Terminal
{
	public:
		static void			write(std::string msg);
		static void			clean();
		static std::string	read(std::string msg);
		static void			wait_enter();
};
