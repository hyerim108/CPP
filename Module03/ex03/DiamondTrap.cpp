/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:18:34 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/09 18:33:25 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
    std::cout << "DiamondTrap created defalut constructor." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
    this->name = name;
    std::cout << "DiamondTrap <" << this->name << "> created constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap)
{
    *this = diamondtrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
    std::cout << "DiamondTrap Operator for DiamondTrap call" << std::endl;
    if (this != &diamondtrap)
    {
        this->name = diamondtrap.name;
        this->hitPoint = diamondtrap.hitPoint;
        this->EnergyPoint = diamondtrap.EnergyPoint;
        this->AttackDamage = diamondtrap.AttackDamage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap <" << this->name << "> destoryed." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    if (!this->hitPoint || !this->EnergyPoint)
        std::cout << "DiamondTrap <" << this->name << "> 0 energyPoint.";
    else
    {
        --EnergyPoint;
        std::cout << "DiamondTrap <" << this->name << "> attack <" << target << ">, causing " << this->AttackDamage << " point of damage!" << std::endl;
    }
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    if (!this->hitPoint)
        std::cout << "DiamondTrap <" << this->name << "> already deaded." << std::endl;
    else
    {
        this->hitPoint -= amount;
        if (this->hitPoint < 0) 
            this->hitPoint = 0;
        std::cout << "DiamondTrap <" << this->name << "> attack " << amount << "hp" << std::endl;
        std::cout << "DiamondTrap <" << this->name << "> have " << this->hitPoint << "hp" << std::endl;
        if (!this->hitPoint)
            std::cout << "DiamondTrap <" << this->name << "> died." << std::endl;
    }
}

void DiamondTrap::beRepaired(unsigned int amount)
{
    if (!this->hitPoint || !this->EnergyPoint)
        std::cout << "DiamondTrap <" << this->name << "> already deaded." << std::endl;
    else {
        this->hitPoint += amount;
        --EnergyPoint;
        std::cout << "DiamondTrap <" << this->name << "> repaired " << amount << "hp" << std::endl; 
        std::cout << "DiamondTrap <" << this->name << "> have " << this->hitPoint << "hp" << std::endl;
    }
}

void DiamondTrap::whoAmI(void) const
{
    std::cout << "DiamondTrap <" << this->name << ">" <<  std::endl;
    std::cout << "ClapTrap <" << this->ClapTrap::get_name() << ">" << std::endl;
}