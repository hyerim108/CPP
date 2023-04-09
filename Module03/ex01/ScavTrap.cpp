/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 06:00:37 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/09 07:17:36 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap::ClapTrap()
{
    std::cout << "ScavTrap created defalut constructor." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name)
{
    hitPoint = 100;
    EnergyPoint = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap <" << name << "> created constructor." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap)
{
    *this = scavtrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
    std::cout << "ScavTrap Operator for ScavTrap call" << std::endl;
    if (this != &scavtrap)
    {
        this->name = scavtrap.name;
        this->hitPoint = scavtrap.hitPoint;
        this->EnergyPoint = scavtrap.EnergyPoint;
        this->AttackDamage = scavtrap.AttackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap <" << this->name << "> destoryed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (!this->hitPoint || !this->EnergyPoint)
        std::cout << "ScavTrap <" << this->name << "> 0 energyPoint.";
    else
    {
        --EnergyPoint;
        std::cout << "ScavTrap <" << this->name << "> attack <" << target << ">, causing " << this->AttackDamage << " point of damage!" << std::endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (!this->hitPoint)
        std::cout << "ScavTrap <" << this->name << "> already deaded." << std::endl;
    else
    {
        this->hitPoint -= amount;
        if (this->hitPoint < 0) 
            this->hitPoint = 0;
        std::cout << "ScavTrap <" << this->name << "> attack " << amount << "hp" << std::endl;
        std::cout << "ScavTrap <" << this->name << "> have " << this->hitPoint << "hp" << std::endl;
        if (!this->hitPoint)
            std::cout << "ScavTrap <" << this->name << "> died." << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (!this->hitPoint || !this->EnergyPoint)
        std::cout << "ScavTrap <" << this->name << "> already deaded." << std::endl;
    else {
        this->hitPoint += amount;
        --EnergyPoint;
        std::cout << "ScavTrap <" << this->name << "> repaired " << amount << "hp" << std::endl; 
        std::cout << "ScavTrap <" << this->name << "> have " << this->hitPoint << "hp" << std::endl;
    }
}

void ScavTrap::guardGate(void) const
{
    std::cout << "ScavTrap <" << this->name << "> guardGate" << std::endl;
}