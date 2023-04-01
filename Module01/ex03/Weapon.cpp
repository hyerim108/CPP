/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:31:35 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/01 16:31:35 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type) {}

const std::string Weapon::getType(void)
{
    return (this->type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}