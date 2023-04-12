/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:24:26 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 16:41:15 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();

	std::cout << std::endl;
	
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();

	std::cout << std::endl;

	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();

	std::cout << std::endl;

	delete meta;
	meta = NULL;
	delete j;
	j = NULL;
	delete i;
	i = NULL;

	delete wrong;
	wrong = NULL;
	
	return (0);
}