/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:18:32 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/09 18:25:05 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap{
    private:
        std::string name;
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name); 
        DiamondTrap(const DiamondTrap &diamondtrap);
        DiamondTrap &operator=(const DiamondTrap &diamondtrap);
        ~DiamondTrap(void);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void whoAmI(void) const;
};

#endif