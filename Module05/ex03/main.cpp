/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:15:46 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/26 17:28:18 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern people;
	Bureaucrat b1("A", 146);
	AForm* f1 = people.makeForm("shrubbery creation", "Form"); //145
	people.makeForm("Wrong", "Not create");

	if (!f1)
		return (1);
	std::cout << b1 << std::endl;
	std::cout << *f1 << std::endl;
	b1.signForm(*f1); //146 > 145 -> 낮은 등급 no sign
	b1.executeForm(*f1); //signed이 안되어있다는 표시!

	b1.increment();
	b1.increment(); //144

	b1.signForm(*f1); //144 > 145 -> 높은등급 sign
	std::cout << *f1 << std::endl;
	b1.executeForm(*f1);
	std::cout << "----------------------------------" << std::endl;
	delete f1;
	return (0);
}
