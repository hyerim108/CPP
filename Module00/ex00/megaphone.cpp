/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:28:09 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/01 16:28:09 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i=1;av[i];i++)
        {
            for(int j=0;av[i][j];j++)
                std::cout << (char)std::toupper(av[i][j]);
        }
    }
    std::cout << std::endl;
    return 0;
}