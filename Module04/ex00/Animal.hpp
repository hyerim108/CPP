/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:37:27 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 16:01:35 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal(void);
        Animal(const Animal &animal);
        Animal &operator=(const Animal &animal);
        virtual ~Animal(void);

        virtual void makeSound() const;
        virtual const std::string& getType() const;
};

#endif