/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:15:40 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/24 17:20:38 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
        Bureaucrat(void);
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        Bureaucrat &operator=(const Bureaucrat &bureaucrat);
        ~Bureaucrat(void);

        std::string getName() const;
        int     getGrade() const;
        void    increment();
        void    decrement();

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

        void signForm(Form &f);
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif