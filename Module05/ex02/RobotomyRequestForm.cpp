/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:07:32 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/26 15:38:23 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm",72,45), target(target)
{
    std::cout << "RobotomyRequestForm was construcred" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rr) : AForm(rr)
{
    std::cout << "RobotomyRequestForm copy was constructed" << std::endl;
    *this = rr;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rr) 
{
    std::cout << "Assignment Operator for RobotomyRequestForm call" << std::endl;
    if (this != &rr)
    {
        this->target = rr.target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destoryed." << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &excutor) const
{
    AForm::checkExce(excutor);
    //드릴소리..?
    std::cout << "** Drill sound **" << std::endl;
    std::cout << "Drrrrrrrrrrrrrrrrrrr....!" << std::endl;
    if (rand() % 2)
    {
        std::cout << "<" <<  this->target << "> successfully robot" << std::endl;
    }
    else
        std::cout << "<" <<  this->target << "> faild robot" << std::endl;
}