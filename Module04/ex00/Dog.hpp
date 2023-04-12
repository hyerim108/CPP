/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:38:01 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 16:01:31 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
    public:
        Dog(void);
        Dog(const Dog &dog);
        Dog &operator=(const Dog &dog);
        virtual ~Dog(void);

        virtual void makeSound() const;
        virtual const std::string& getType() const;
};

#endif