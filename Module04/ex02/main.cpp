/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:24:26 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 19:53:23 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	//Animal *p = new Animal();
	Dog *d = new Dog();
	//delete p;
	std::cout << d->getType() << " " << std::endl;
	d->makeSound();
	delete d;
	return (0);
}
