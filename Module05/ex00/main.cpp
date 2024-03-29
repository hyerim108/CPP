/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:15:46 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/24 15:00:38 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "----- Test Bureaucrat grade -----" << std::endl;
	Bureaucrat p1("apple", 1);
	Bureaucrat p2("banana", 150);
	std::cout << std::endl;
	std::cout << "p1 Before : " << p1;
	p1.decrement();
	std::cout << "p1 After : " << p1;
	std::cout << "p2 Before : " << p2;
	p2.increment();
	std::cout << "p2 After : " << p2 << std::endl;

	std::cout << "----- Test Example -----" << std::endl;
	try
	{
		Bureaucrat p3("grape", 0);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat p4("cherry", 151);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}