/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:45:35 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 17:30:09 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
    std::cout << "WrongAnimal created defalut constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
    *this = wronganimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
    std::cout << "Assignment Operator for WrongAnimal call" << std::endl;
    if (this != &wronganimal) 
        this->type = wronganimal.type;
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destoryed." << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::setType(const std::string &type)
{
    this->type = type;
}