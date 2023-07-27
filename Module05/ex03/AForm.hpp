/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:09:13 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/27 14:10:25 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm{
    private:
        std::string const name;
        bool sign;
        int const grade;
        int const gradeEx;
    public:
        AForm(void);
        AForm(std::string const name, int grade, int gradeEx);
        AForm(const AForm &form);
        AForm &operator=(const AForm &form);
        virtual ~AForm(void);

        std::string getName() const;
        int     getGrade() const;
        int     getGradeEx() const;
        bool    getSign() const;
        
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

        class FormNoSingedException:public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        virtual void beSigned(const Bureaucrat &executor);
        virtual void execute(Bureaucrat const & executor) const = 0;
        void checkExce( Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif