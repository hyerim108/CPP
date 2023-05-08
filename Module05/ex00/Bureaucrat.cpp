/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:15:43 by hyerimki          #+#    #+#             */
/*   Updated: 2023/05/08 16:30:12 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    std::cout << "Bureaucrat was construcred" << std::endl;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name)
{
    std::cout << "Bureaucrat copy was constructed" << std::endl;
    *this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) 
{
    std::cout << "Assignment Operator for Bureaucrat call" << std::endl;
    if (this != &bureaucrat)
    {
        this->grade = bureaucrat.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destoryed." << std::endl;
}

std::string Bureaucrat::getName(void) const
{
    return this->name;
}

int Bureaucrat::getGrade(void) const
{
    return this->grade;
}

void Bureaucrat::increment(void)
{
    if(this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrement(void)
{
    if(this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}
const char* Bureaucrat::GradeTooHighException::what()  const throw()
{
    return ("Grade is higher than 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is lower than 150");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
    o << "<" << bureaucrat.getName() << "> bureaucrat grade is " << bureaucrat.getGrade() << std::endl;
    return o;
}