/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:45:16 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 17:30:19 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : type("WrongCat")
{
    std::cout << "WrongCat created defalut constructor." << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongcat)
{
    *this = wrongcat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
    std::cout << "Assignment Operator for WrongCat call" << std::endl;
    if (this != &wrongcat) 
        this->type = wrongcat.type;
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destoryed." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}

const std::string& WrongCat::getType() const
{
    return this->type;
}

void WrongCat::setType(const std::string &type)
{
    this->type = type;
}