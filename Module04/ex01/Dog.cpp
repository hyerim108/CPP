/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:38:00 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 19:41:42 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : brain(new Brain)
{
    std::cout << "Dog created defalut constructor." << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &dog)
{
    this->brain = new Brain;
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
    std::cout << "Assignment Operator for Dog call" << std::endl;
    if (this != &dog)
    {
        this->type = dog.type;
        *this->brain = *dog.brain;
    }
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog destoryed." << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "woof ! woof !" << std::endl;
}

const std::string& Dog::getType() const
{
    return this->type;
}

const Brain &Dog::get_brain() const
{
    return *this->brain;
}