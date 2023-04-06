/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:42:00 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/06 19:36:02 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap apple = FragTrap("apple");
	FragTrap banana = FragTrap("banana");

	apple.takeDamage(10);
	apple.takeDamage(10);
	apple.beRepaired(7);
	apple.takeDamage(10);
	apple.highFivesGuys();
	return (0);
}