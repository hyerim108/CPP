/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:40:34 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/13 15:41:16 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    Span v(10);

    try{
        v.addNumber(6);
        v.addNumber(3);
        v.addNumber(17);
        v.addNumber(9);
        v.addNumber(11);
        v.addNumber(1);
        v.addNumber(2);
        v.addNumber(4);
        v.addNumber(5);
        v.addNumber(7);
        // v.addNumber(13);
    }catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << v.shortestSpan() << std::endl;
        std::cout << v.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}