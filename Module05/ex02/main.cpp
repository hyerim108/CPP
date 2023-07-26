/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:15:46 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/26 15:50:43 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	PresidentialPardonForm pardon("Pardon"); //25
	RobotomyRequestForm robotomy("Robotomy"); //72
	ShrubberyCreationForm shrubbery("Shrubbbery"); //145
	
	Bureaucrat apple("Apple", 150);
	Bureaucrat banana("Banana", 120);
	Bureaucrat melon("Melon", 3);

	std::cout << "\n *First Try* \n";

	std::cout << apple << std::endl;
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;
	apple.executeForm(shrubbery);
	apple.executeForm(robotomy);
	apple.executeForm(pardon);
	
	std::cout << "\n *Second Try* \n";

	std::cout << apple << std::endl;
	std::cout << banana << std::endl;
	banana.signForm(shrubbery);
	std::cout << shrubbery << std::endl;
	apple.executeForm(shrubbery);

	std::cout << "\n *Third Try* \n";

	melon.signForm(robotomy);
	melon.signForm(pardon);
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;
	std::cout << "---------------------------- \n";
	melon.executeForm(shrubbery);
	std::cout << "---------------------------- \n";
	melon.executeForm(robotomy);
	std::cout << "---------------------------- \n";
	melon.executeForm(pardon);
	std::cout << "---------------------------- \n";

	return (0);
}
