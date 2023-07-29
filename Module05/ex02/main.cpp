/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:15:46 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/27 16:41:43 by hyerimki         ###   ########.fr       */
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
	/*  정보 출력*/
	std::cout << apple << std::endl;
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl; 
	/* sign이 되어있는지 등급이 충분히 높은지 확인!*/
	apple.executeForm(shrubbery);
	apple.executeForm(robotomy);
	apple.executeForm(pardon); // 전체 사인 false임으로 사인이 되어있지 않음을 throw
	
	std::cout << "\n *Second Try* \n";

	std::cout << apple << std::endl;
	std::cout << banana << std::endl; //정보출력
	banana.signForm(shrubbery); //바나나 120 shrubbery 145 banana가 높은 등급임으로 사인
	std::cout << shrubbery << std::endl; //shrubbery sign바뀌었는지 확인
	apple.executeForm(shrubbery); //shruberry 145 < apple 150 apple이 낮음 throw

	std::cout << "\n *Third Try* \n";

	melon.signForm(robotomy); 
	melon.signForm(pardon); //melon이 더 높기 때문에 사인 5 <= 72 or 25
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl; //사인되었는지 확인
	std::cout << "---------------------------- \n";
	melon.executeForm(shrubbery); //tree file
	std::cout << "---------------------------- \n";
	melon.executeForm(robotomy); //로봇화
	std::cout << "---------------------------- \n";
	melon.executeForm(pardon); //출력
	std::cout << "---------------------------- \n"; //사인과 등급 모두 통과해서 실행되는지 확인

	return (0);
}
