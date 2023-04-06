/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:13:14 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/06 19:43:19 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap::ClapTrap()
{
    std::cout << "FragTrap was constructed" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name)
{
    hit = 100;
    energy = 50;
    attackDamage = 20;
    std::cout << "FragTrap <" << name << "> was constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap)
{
    *this = fragtrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
    std::cout << "ScavTrap <" << fragtrap.name << "> was copied" << std::endl;
    if (this != &fragtrap)
    {
        this->name = fragtrap.name;
        this->hit = fragtrap.hit;
        this->energy = fragtrap.energy;
        this->attackDamage = fragtrap.attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap <" << this->name << "> destoryed." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (this->energy)
    {
        --energy;
        std::cout << " FragTrap <" << this->name << "> attacks <" << target << ">, causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "FragTrap <" << this->name << "> has 0 energy" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (!hit)
        std::cout << "FragTrap <" << this->name << "> already dead" << std::endl;
    else
    {
        this->hit -= amount;
        if(this->hit < 0)
            this->hit = 0;
        std::cout << "FragTrap <" << this->name << "> attacked " << amount << " hp" << std::endl;
        std::cout << "FragTrap <" << this->name << "> have " << this->hit << " hp" << std::endl;
        if (!this->hit)
            std::cout << "FragTrap <" << this->name << "> died" << std::endl;
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    this->hit += amount;
    if(this->energy)
    {
        --energy;
        std::cout << "FragTrap <" << this->name << "> healed " << amount << " hp" << std::endl;
        std::cout << "FragTrap <" << this->name << "> have " << this->hit << " hp" << std::endl;
    }
    else
        std::cout << "FragTrap <" << this->name << "> has 0 energyPoint" << std::endl;
}

void FragTrap::highFivesGuys(void) const
{
    std::cout << "FragTrap <" << this->name << "> highFive" << std::endl;
}