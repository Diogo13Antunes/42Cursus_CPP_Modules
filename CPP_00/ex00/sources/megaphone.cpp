/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:25:15 by dcandeia          #+#    #+#             */
/*   Updated: 2022/10/31 10:45:29 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void    print_upper(char **matrix)
{
    int i = 1;
    int j = 0;

    while (matrix[i])
    {
        j = 0;
        while (matrix[i][j])
        {
            if (matrix[i][j] >= 'a' && matrix[i][j] <= 'z')
                std::cout << (matrix[i][j] -= 32);
            else
                std::cout << (matrix[i][j]);
            j++;
        }
        i++;
    }
    std::cout << "\n";
}

int main(int ac, char **av)
{
    if (ac > 1)
        print_upper(av);
    else
        std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE * "<< std::endl;
}
