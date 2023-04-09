/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 04:57:51 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/09 05:56:12 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name(""), hitPoint(10), EnergyPoint(10), AttackDamage(0)
{
    std::cout << "ClapTrap <" << this->name << "> created defalut constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), EnergyPoint(10), AttackDamage(0) 
{
    std::cout << "ClapTrap <" << this->name << "> created constructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
    *this = claptrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
    std::cout << "Assignment Operator for ClapTrap call" << std::endl;
    if (this != &claptrap)
    {
        this->name = claptrap.name;
        this->hitPoint = claptrap.hitPoint;
        this->EnergyPoint = claptrap.EnergyPoint;
        this->AttackDamage = claptrap.AttackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap <" << this->name << "> destoryed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (!this->hitPoint || !this->EnergyPoint)
        std::cout << "ClapTrap <" << this->name << "> 0 energyPoint.";
    else
    {
        --EnergyPoint;
        std::cout << "ClapTrap <" << this->name << "> attack <" << target << ">, causing " << this->AttackDamage << " point of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!this->hitPoint)
        std::cout << "ClapTrap <" << this->name << "> already deaded." << std::endl;
    else
    {
        this->hitPoint -= amount;
        if (this->hitPoint < 0) 
            this->hitPoint = 0;
        std::cout << "ClapTrap <" << this->name << "> attack " << amount << "hp" << std::endl;
        std::cout << "ClapTrap <" << this->name << "> have " << this->hitPoint << "hp" << std::endl;
        if (!this->hitPoint)
            std::cout << "ClapTrap <" << this->name << "> died." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->hitPoint || !this->EnergyPoint)
        std::cout << "ClapTrap <" << this->name << "> already deaded." << std::endl;
    else {
        this->hitPoint += amount;
        --EnergyPoint;
        std::cout << "ClapTrap <" << this->name << "> repaired " << amount << "hp" << std::endl; 
        std::cout << "ClapTrap <" << this->name << "> have " << this->hitPoint << "hp" << std::endl;
    }
}