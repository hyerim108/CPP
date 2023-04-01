/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:29:27 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/01 16:29:28 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *heap = newZombie("heap call");
	heap->announce();
	delete heap;

	Zombie stack = Zombie("Stack call");
	stack.announce();

	randomChump("Random");
	return (0);
}