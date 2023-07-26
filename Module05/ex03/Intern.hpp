/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:52:45 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/26 16:56:45 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

class Intern{
    private:
        /* data : 특별한 특징 없음*/
    public:
        /* Canonical */
        Intern(void);
        Intern(const Intern &intern);
        Intern &operator=(const Intern &intern);
        ~Intern();

        AForm* makeForm(std::string name, std::string target);
        AForm* newShrubbery(std::string target);
        AForm* newRobotomy(std::string target);
        AForm* newPresidential(std::string target);
};

#endif