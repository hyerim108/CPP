/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:09:13 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/27 14:08:08 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form{
    private:
        std::string const name;
        bool sign;
        int const grade;
        int const gradeEx;
    public:
        Form(void);
        Form(std::string const name, int grade, int gradeEx);
        Form(const Form &form);
        Form &operator=(const Form &form);
        ~Form(void);

        std::string getName() const;
        int     getGrade() const;
        int     getGradeEx() const;
        bool    getSign() const;
        
        void    beSigned(const Bureaucrat &b);
        
        class GradeTooHighException:public std::exception
        {
            public:
                const char* what() const throw();
                ~GradeTooHighException(void) throw();
        };
        class GradeTooLowException:public std::exception
        {
            public:
                const char* what() const throw();
                ~GradeTooLowException(void) throw();
        };
};

std::ostream &operator<<(std::ostream &o, const Form &form);

#endif