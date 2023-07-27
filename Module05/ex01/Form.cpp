/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:09:21 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/26 17:45:12 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const name, int grade, int gradeEx) : name(name), grade(grade), gradeEx(gradeEx)
{
    std::cout << "Form was construcred" << std::endl;
    if (grade > 150 || gradeEx > 150) //등급이 150보다 낮을경우
        throw GradeTooLowException();
    else if(grade < 1 || gradeEx < 1)
        throw GradeTooHighException(); //등급이 1보다 높을경우
}

Form::Form(const Form &form) : name(form.name), grade(form.grade), gradeEx(form.gradeEx)
{
    std::cout << "Form copy was constructed" << std::endl;
    *this = form;
}

Form &Form::operator=(const Form &form) 
{
    std::cout << "Assignment Operator for Form call" << std::endl;
    if (this != &form)
    {
        this->sign = form.sign;
    }
    return (*this);
}

Form::~Form(void)
{
    std::cout << "Form destoryed." << std::endl;
}

std::string Form::getName(void) const
{
    return this->name;
}

int Form::getGrade(void) const
{
    return this->grade;
}

int Form::getGradeEx(void) const
{
    return this->gradeEx;
}

bool Form::getSign(void) const
{
    return this->sign;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->grade) //b가 충충분분히 높다면 -> 1이 150보다 높은 등급 
        this->sign = true;
    else if(b.getGrade() > this->grade) //낮아버리면 등급낮다는 에러표시
        throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
    o << "------------" << "Form : " << form.getName() << "------------"<< std::endl;
    o << "<Form Grade> : " << form.getGrade() << std::endl;
    o << "<Form CretainGrade> : " << form.getGradeEx() << std::endl;
    o << "<Form sign> : " << (form.getSign() ? "YES" : "NO") << std::endl;
    o << "------------------------------------" << std::endl;
    return o;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Exception : Form Grade higher than  1");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Exception : Grade less than required");
}

Form::GradeTooHighException::~GradeTooHighException(void) throw(){}
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}