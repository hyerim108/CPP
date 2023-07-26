/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:15:43 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/26 14:23:12 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    std::cout << "Bureaucrat was construcred" << std::endl;
    if (grade < 1)
        throw GradeTooHighException(); 
    else if(grade > 150)
        throw GradeTooLowException(); //1보다 많거나 150보다 더 적은 등급이 들어올 경우 에러처리
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

void Bureaucrat::increment()
{
    if (this->grade == 1)  //등급증가 1이하의 수가 들어올 경우 에러처리
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrement() 
{
    if (this->grade == 150) //등급감소 150이상의 수가 들어올 경우 에러처리
        throw GradeTooLowException();
    this->grade++;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
    o << "<" << bureaucrat.getName() << "> bureaucrat grade <" << bureaucrat.getGrade() << ">" << std::endl;
    return o;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Exception : Grade higher than  1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Exception : Grade less than 150");
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw(){}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}