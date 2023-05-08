/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:15:40 by hyerimki          #+#    #+#             */
/*   Updated: 2023/05/08 16:18:30 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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
        void    increment(void);
        void    decrement(void);
        
        class GradeTooHighException : public std::exception
        {
            public:
                ~GradeTooHighException(void) throw();
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                ~GradeTooLowException(void) throw();
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif