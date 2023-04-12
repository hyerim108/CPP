/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:37:29 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 19:55:41 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("")
{
    std::cout << "Animal created defalut constructor." << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal &animal)
{
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
    std::cout << "Assignment Operator for Animal call" << std::endl;
    if (this != &animal)
    {
        this->type = animal.type;
    }
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal destoryed." << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "no sound" << std::endl;
}

const std::string& Animal::getType() const
{
    return this->type;
}
