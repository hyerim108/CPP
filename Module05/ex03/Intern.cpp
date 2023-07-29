/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:52:47 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/27 14:22:26 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
    std::cout << "Intern was construcred" << std::endl;
}

Intern::Intern(const Intern &intern)
{
    std::cout << "Intern copy was constructed" << std::endl;
    *this = intern;
}

Intern &Intern::operator=(const Intern &intern) 
{
    std::cout << "Assignment Operator for Intern call" << std::endl;
    (void) intern;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destoryed." << std::endl;
}

AForm* Intern::newShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::newRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::newPresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string form, std::string target)
{
    std::string s[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*p[3])(std::string) = {&Intern::newShrubbery, &Intern::newRobotomy, &Intern::newPresidential};
    int i = 0;
    while (i < 4 && s[i].compare(form) != 0)
        i++;
    if (i < 3)
    {
        std::cout << "Intern creates : <" << form << ">" << std::endl;
        return ((this->*p[i])(target));
    }
    std::cout << "Exception : formName <" << form << "> is failed" << std::endl;
    return (NULL);
}