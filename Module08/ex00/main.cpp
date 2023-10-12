/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:37:38 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/12 15:36:42 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    
    try{
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value: " << *it << "\n";

        it = easyfind(vec, 6);
        std::cout << "Found value: " << *it << "\n";
    }catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}