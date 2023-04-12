/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:24:26 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 19:42:03 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void test1() {
	std::cout << "*** [TEST 1] ***" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
}

void test2() {
	std::cout << std::endl << "*** [TEST 2] ***" << std::endl;
	Animal* animals[4];
	std::cout << "[TEST 2] Create Array of Cats and Dogs!" << std::endl;
	for(int i = 0; i < 4; i++) {
		if (i < 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << "[TEST 2] Animals making sounds!" << std::endl;
	for(int i = 0; i < 4; i++) {
		animals[i]->makeSound();
	}
	std::cout << "[TEST 2] Delete Cats and Dogs!" << std::endl;
	for(int i = 0; i < 4; i++) {
		delete animals[i];
	}
}

void test3() {
	std::cout << std::endl << "*** [TEST 3] ***" << std::endl;
	std::cout << "[TEST 3] Create a Dog and a Cat!" << std::endl;
	const Dog a;
	const Cat b;

	std::cout << "[TEST 3] Create a copies of Dog and Cat!" << std::endl;
	const Dog c = a;
	const Cat d = b;

	std::cout << "Memory address of Dog a's brain is      : " << &a.get_brain() << std::endl;
	std::cout << "Memory address of Copy Dog c's brain is : " << &c.get_brain() << std::endl;

	std::cout << "Memory address of Cat b's brain is      : " << &b.get_brain() << std::endl;
	std::cout << "Memory address of Copy Cat d's brain is : " << &d.get_brain() << std::endl;
}

int main() {
	test1();
	test2();
	test3();
	// while(1);
	return (0);
}
