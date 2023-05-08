/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:15:46 by hyerimki          #+#    #+#             */
/*   Updated: 2023/05/08 16:20:55 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "----- Test Bureaucrat grade -----" << std::endl;
	Bureaucrat p1("apple", 1);
	Bureaucrat p2(p1);
	Bureaucrat p3("banana", 150);
	Bureaucrat p4("mango", 150);
	std::cout << std::endl;
	std::cout << "Before decrement : " << p2;
	p2.decrement();
	std::cout << "After increment : " << p2;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Before increment : " << p4;
	p4.increment();
	std::cout << "After increment : " << p4 << std::endl;

	std::cout << "----- Test Exception -----" << std::endl;
	try
	{
		Bureaucrat p5("watermelen", 0);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat p6("cherry", 151);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		p1.increment();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		p3.decrement();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}