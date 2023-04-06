/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:41:54 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/06 15:58:13 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name(""), hit(10), energy(10), attackDamage(0)
{
    std::cout << "ClapTrap <" << this->name << "> created with default." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit(10), energy(10), attackDamage(0)
{
    std::cout << "ClapTrap <" <<  this->name << "> created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
    *this = claptrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
    std::cout << "Assignement operator for ClapTrap called." << std::endl;
    if (this != &claptrap)
    {
        this->name = claptrap.name;
        this->hit = claptrap.hit;
        this->energy = claptrap.energy;
        this->attackDamage = claptrap.attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap <" << this->name << "> destoryed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->energy)
    {
        --energy;
        std::cout << " ClapTrap <" << this->name << "> attacks <" << target << ">, causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap <" << this->name << "> has 0 energy" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!hit)
        std::cout << "ClapTrap <" << this->name << "> already dead" << std::endl;
    else
    {
        this->hit -= amount;
        if(this->hit < 0)
            this->hit = 0;
        std::cout << "ClapTrap <" << this->name << "> attacked " << amount << " hp" << std::endl;
        std::cout << "ClapTrap <" << this->name << "> have " << this->hit << " hp" << std::endl;
        if (!this->hit)
            std::cout << "ClapTrap <" << this->name << "> died" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->hit += amount;
    if(this->energy)
    {
        --energy;
        std::cout << "ClapTrap <" << this->name << "> healed " << amount << " hp" << std::endl;
        std::cout << "ClapTrap <" << this->name << "> have " << this->hit << " hp" << std::endl;
    }
    else
        std::cout << "ClapTrap <" << this->name << "> has 0 energyPoint" << std::endl;
}