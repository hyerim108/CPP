/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:07:09 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/26 15:19:28 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARADONFORM_HPP
#define PRESIDENTIALPARADONFORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    private:
        std::string target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &pp);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &pp);
        ~PresidentialPardonForm(void);

        void execute(const Bureaucrat &excutor) const;
};

#endif