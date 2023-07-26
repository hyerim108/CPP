/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:07:04 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/26 15:38:20 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm",25,5), target(target) 
{
    std::cout << "PresidentialPardonForm was construcred" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &pp) : AForm(pp)
{
    std::cout << "PresidentialPardonForm copy was constructed" << std::endl;
    *this = pp;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &pp) 
{
    std::cout << "Assignment Operator for PresidentialPardonForm call" << std::endl;
    if (this != &pp)
    {
        this->target = pp.target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destoryed." << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &excutor) const
{
    AForm::checkExce(excutor);
    std::cout << "<" << this->target << "> has been pardoned by Zaphod Beeblebrox." << std::endl;
}