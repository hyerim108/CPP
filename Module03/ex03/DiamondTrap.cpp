/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:44:53 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/06 20:13:55 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
    std::cout << "DiamondTrap was constructed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
    this->name = name;
    std::cout << "DiamondTrap <" << this->name << "> was constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap)
{
    *this = diamondtrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
    std::cout << "DiamondTrap <" << diamondtrap.name << "> was copied" << std::endl;
    if (this != &diamondtrap)
    {
        this->name = diamondtrap.name;
        this->hit = diamondtrap.hit;
        this->energy = diamondtrap.energy;
        this->attackDamage = diamondtrap.attackDamage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap <" << this->name << "> destoryed." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    if (this->energy)
    {
        --energy;
        std::cout << " DiamondTrap <" << this->name << "> attacks <" << target << ">, causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "DiamondTrap <" << this->name << "> has 0 energy" << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    if (!hit)
        std::cout << "DiamondTrap <" << this->name << "> already dead" << std::endl;
    else
    {
        this->hit -= amount;
        if(this->hit < 0)
            this->hit = 0;
        std::cout << "DiamondTrap <" << this->name << "> attacked " << amount << " hp" << std::endl;
        std::cout << "DiamondTrap <" << this->name << "> have " << this->hit << " hp" << std::endl;
        if (!this->hit)
            std::cout << "DiamondTrap <" << this->name << "> died" << std::endl;
    }
}

void DiamondTrap::beRepaired(unsigned int amount)
{
    this->hit += amount;
    if(this->energy)
    {
        --energy;
        std::cout << "DiamondTrap <" << this->name << "> healed " << amount << " hp" << std::endl;
        std::cout << "DiamondTrap <" << this->name << "> have " << this->hit << " hp" << std::endl;
    }
    else
        std::cout << "DiamondTrap <" << this->name << "> has 0 energyPoint" << std::endl;
}

void DiamondTrap::whoAmI(void) const
{
    std::cout << "DiamondTrap <" << name << ">" << std::endl;
    std::cout << "ClapTrap <" << this->ClapTrap::get_name() << ">" << std::endl;
}