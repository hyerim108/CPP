/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:31:23 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/06 15:01:59 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, const Weapon &weapon): name(name), weapon(weapon) {}

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << \
    weapon.getType() << std::endl;
}