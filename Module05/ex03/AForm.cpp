/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:09:21 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/26 15:39:11 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const name, int grade, int certain_grade) : name(name), grade(grade), certain_grade(certain_grade)
{
    std::cout << "AForm was construcred" << std::endl;
    if (grade > 150 || certain_grade > 150) //등급이 150보다 낮을경우
        throw GradeTooLowException();
    else if(grade < 1 || certain_grade < 1)
        throw GradeTooHighException(); //등급이 1보다 높을경우
}

AForm::AForm(const AForm &form) : name(form.name), grade(form.grade), certain_grade(form.certain_grade)
{
    std::cout << "AForm copy was constructed" << std::endl;
    *this = form;
}

AForm &AForm::operator=(const AForm &form) 
{
    std::cout << "Assignment Operator for AForm call" << std::endl;
    if (this != &form)
    {
        this->sign = form.sign;
    }
    return (*this);
}

AForm::~AForm(void)
{
    std::cout << "AForm destoryed." << std::endl;
}

std::string AForm::getName(void) const
{
    return this->name;
}

int AForm::getGrade(void) const
{
    return this->grade;
}

int AForm::getCertainGrade(void) const
{
    return this->certain_grade;
}

bool AForm::getSign(void) const
{
    return this->sign;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->grade) //b가 충충분분히 높다면 -> 1이 150보다 높은 등급 
        this->sign = true;
    else if(b.getGrade() > this->grade) //낮아버리면 등급낮다는 에러표시
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, const AForm &form)
{
    o << "---------" << "AForm : " << form.getName() << "--------"<< std::endl;
    o << "<AForm Grade> : " << form.getGrade() << std::endl;
    o << "<AForm CretainGrade> : " << form.getCertainGrade() << std::endl;
    o << "<AForm sign> : " << (form.getSign() ? "YES" : "NO") << std::endl;
    o << "------------------------------------" << std::endl;
    return o;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Exception : Form Grade higher than  1");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Exception : Grade less than required");
}

const char* AForm::FormNoSingedException::what() const throw()
{
    return ("Exception : Form is not signed !");
}

AForm::GradeTooHighException::~GradeTooHighException(void) throw(){}
AForm::GradeTooLowException::~GradeTooLowException(void) throw() {}

void AForm::checkExce(Bureaucrat const & executor) const
{
    if (this->sign == false)
        throw FormNoSingedException();
    if(executor.getGrade() > this->grade) //b의 등급이 충분히 높은지 확인 b가 더 높으면 낮은 등급
        throw GradeTooLowException();
}