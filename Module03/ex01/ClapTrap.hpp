/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:41:57 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/03 17:37:20 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CPP
#define CLAPTRAP_CPP

#include <iostream>
#include <string>

class ClapTrap{
    private:
        std::string name;
        int hit;
        int energy;
        int attackDamage;
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &claptrap);
        ClapTrap &operator=(const ClapTrap &claptrap);
        ~ClapTrap(void);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif