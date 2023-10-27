/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:11:39 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/27 15:47:44 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Argument Error : [./RPN] [expression]" << std::endl;
        return (1);
    }
    RPN r;
    try
    {
        r.formRPN(av[1]);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    return 0;
}