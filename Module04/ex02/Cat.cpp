/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:37:58 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 19:41:09 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : brain(new Brain)
{
    std::cout << "Cat created defalut constructor." << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &cat)
{
    this->brain = new Brain;
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "Assignment Operator for Cat call" << std::endl;
    if (this != &cat)
    {
        this->type = cat.type;
        *this->brain = *cat.brain;
    }
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destoryed." << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "meow ~ meow ~" << std::endl;
}

const std::string& Cat::getType() const
{
    return this->type;
}

const Brain &Cat::get_brain() const
{
    return *this->brain;
}