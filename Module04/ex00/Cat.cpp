/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:37:58 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/10 18:14:09 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal::Animal();
{
    std::cout << "Cat created defalut constructor." << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &cat)
{
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "Assignment Operator for Cat call" << std::endl;
    if (this != &cat) 
        this->type = cat.type;
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destoryed." << std::endl;
}