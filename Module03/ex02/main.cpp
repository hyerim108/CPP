/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 04:57:56 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/09 07:26:06 by hyerimki         ###   ########.fr       */
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
	// apple.highFivesGuys();
	return (0);
}