/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 07:21:18 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/09 07:29:23 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap::ClapTrap()
{
    std::cout << "FragTrap created defalut constructor." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name)
{
    hitPoint = 100;
    EnergyPoint = 50;
    AttackDamage = 20;
    std::cout << "FragTrap <" << name << "> created constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap)
{
    *this = fragtrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
    std::cout << "FragTrap Operator for FragTrap call" << std::endl;
    if (this != &fragtrap)
    {
        this->name = fragtrap.name;
        this->hitPoint = fragtrap.hitPoint;
        this->EnergyPoint = fragtrap.EnergyPoint;
        this->AttackDamage = fragtrap.AttackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap <" << this->name << "> destoryed." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (!this->hitPoint || !this->EnergyPoint)
        std::cout << "FragTrap <" << this->name << "> 0 energyPoint.";
    else
    {
        --EnergyPoint;
        std::cout << "FragTrap <" << this->name << "> attack <" << target << ">, causing " << this->AttackDamage << " point of damage!" << std::endl;
    }
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (!this->hitPoint)
        std::cout << "FragTrap <" << this->name << "> already deaded." << std::endl;
    else
    {
        this->hitPoint -= amount;
        if (this->hitPoint < 0) 
            this->hitPoint = 0;
        std::cout << "FragTrap <" << this->name << "> attack " << amount << "hp" << std::endl;
        std::cout << "FragTrap <" << this->name << "> have " << this->hitPoint << "hp" << std::endl;
        if (!this->hitPoint)
            std::cout << "FragTrap <" << this->name << "> died." << std::endl;
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (!this->hitPoint || !this->EnergyPoint)
        std::cout << "FragTrap <" << this->name << "> already deaded." << std::endl;
    else {
        this->hitPoint += amount;
        --EnergyPoint;
        std::cout << "FragTrap <" << this->name << "> repaired " << amount << "hp" << std::endl; 
        std::cout << "FragTrap <" << this->name << "> have " << this->hitPoint << "hp" << std::endl;
    }
}