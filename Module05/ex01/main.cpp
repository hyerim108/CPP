/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:15:46 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/27 16:33:58 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "----- Test Bureaucrat grade -----" << std::endl;
	Form f1("Form 1", 20, 60);
	Form f2("Form 2", 30 , 2);
	
	Bureaucrat b1("Bureaucrat 1", 15);
	Bureaucrat b2("Bureaucrat 2", 36);

	std::cout << f1 << std::endl;
	std::cout << b1 << std::endl; //정보 출력
	b1.signForm(f1); // 15 > 20 sign true
	
	std::cout << f2 << std::endl;
	std::cout << b2 << std::endl;
	b2.signForm(f2); // 36 < 30 f의 등급이 더 높기 때문에 throw

	std::cout << std::endl;
	std::cout << "----- Test Exception grade -----" << std::endl;
	try
	{
		Form f3("Form 3", 140, -1); // 생성시 요구하는 등급보다 높을때
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form f4("Form 3", 250, 200); //생성시 요구하는 등급보다 낮을때
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}