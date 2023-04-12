/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:38:00 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 15:59:47 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal::Animal()
{
    std::cout << "Dog created defalut constructor." << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &dog)
{
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
    std::cout << "Assignment Operator for Dog call" << std::endl;
    if (this != &dog) 
        this->type = dog.type;
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog destoryed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "woof ! woof !" << std::endl;
}

const std::string& Dog::getType() const
{
    return this->type;
}
