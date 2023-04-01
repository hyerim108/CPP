/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:30:14 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/01 16:30:14 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int size = 20;

    Zombie *horde = zombieHorde(size, "Zom");
    for(int i=0;i<size;i++)
        horde[i].announce();
    delete [] horde;
}