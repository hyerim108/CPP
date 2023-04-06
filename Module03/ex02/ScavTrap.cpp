/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:06:58 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/06 15:58:21 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap::ClapTrap()
{
    std::cout << "ScavTrap was constructed" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name)
{
    hit = 100;
    energy = 50;
    attackDamage = 20;
    std::cout << "ScavTrap <" << name << "> was constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap)
{
    *this = scavtrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
    std::cout << "ScavTrap <" << scavtrap.name << "> was copied" << std::endl;
    if (this != &scavtrap)
    {
        this->name = scavtrap.name;
        this->hit = scavtrap.hit;
        this->energy = scavtrap.energy;
        this->attackDamage = scavtrap.attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap <" << this->name << "> destoryed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->energy)
    {
        --energy;
        std::cout << " ScavTrap <" << this->name << "> attacks <" << target << ">, causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap <" << this->name << "> has 0 energy" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (!hit)
        std::cout << "ScavTrap <" << this->name << "> already dead" << std::endl;
    else
    {
        this->hit -= amount;
        if(this->hit < 0)
            this->hit = 0;
        std::cout << "ScavTrap <" << this->name << "> attacked " << amount << " hp" << std::endl;
        std::cout << "ScavTrap <" << this->name << "> have " << this->hit << " hp" << std::endl;
        if (!this->hit)
            std::cout << "ScavTrap <" << this->name << "> died" << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    this->hit += amount;
    if(this->energy)
    {
        --energy;
        std::cout << "ScavTrap <" << this->name << "> healed " << amount << " hp" << std::endl;
        std::cout << "ScavTrap <" << this->name << "> have " << this->hit << " hp" << std::endl;
    }
    else
        std::cout << "ScavTrap <" << this->name << "> has 0 energyPoint" << std::endl;
}

void ScavTrap::guardGate(void) const
{
    std::cout << "ScavTrap <" << this->name << "> is GateKeeper Mode" << std::endl;
}