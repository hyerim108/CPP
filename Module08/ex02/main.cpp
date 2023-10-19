/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:23:51 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/19 14:27:16 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void first()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    // std::cout << mstack.top() << std::endl;
    // mstack.pop();
    // std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
}

void second(){
    std::list<int> asList;
	asList.push_back(5);
	asList.push_back(17);
	// std::cout << asList.back() << std::endl;
	// asList.pop_back();
	// std::cout << asList.size() << std::endl;
	asList.push_back(3);
	asList.push_back(5);
	asList.push_back(737);

	asList.push_back(0);
	std::list<int>::iterator it = asList.begin();
	std::list<int>::iterator ite = asList.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
    std::cout << "-----------------------------" << std::endl;
    first();
    std::cout << "-----------------------------" << std::endl;
    second();
    return 0;
}

