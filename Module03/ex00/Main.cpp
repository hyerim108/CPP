/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 04:57:56 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/09 05:59:43 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a = ClapTrap("A");
	ClapTrap b = ClapTrap("B");

	a.attack("B"); // a가 b 공격
	b.takeDamage(5); // b가 5 데이지 입고 남은 hp가 5남는것을 출력
	b.beRepaired(3); // 3 회복 해서 8을 가지고 있는것을 출력
	b.attack("A"); // b가 A공격
	a.takeDamage(10); //a가 10 데미지 입고 0 남김
	a.beRepaired(10); //a가 10을 회복하려고 하지만 남은 energypoint와 hp가 없어서 죽었다고 출력
	return (0);
}