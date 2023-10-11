/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:10:02 by hyerimki          #+#    #+#             */
/*   Updated: 2023/09/22 18:49:37 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

#define MAX_VAL 750
int main(void)
{
    std::cout << "< int array > " << std::endl;
	Array <int> array(10);

	std::cout << "< array using [] operator >" << std::endl;
    std::cout << "array Size : " << array.size() << std::endl;
	for(unsigned int i = 0; i < array.size(); i++)
		array[i] = i + 1;
	std::cout << array << std::endl;

    std::cout << "< string array > " << std::endl;
	Array <std::string> array_string(3);

	std::cout << "< array using [] operator >" << std::endl;
    std::cout << "array Size : " << array_string.size() << std::endl;
	for(unsigned int i = 0; i < array_string.size(); i++)
		array_string[i] = 'a' + i;
	std::cout << array_string << std::endl;
    
    Array<int> copy_int(10);
    copy_int = array;
    
    copy_int[0] = -1;
    std::cout << copy_int << std::endl;

    Array<std::string> copy_string;
    copy_string = array_string;
    array_string[0] = "grape";
    array_string[1] = "banana";
    array_string[2] = "watermelon";
    std::cout << copy_string << std::endl;
    std::cout << array_string << std::endl;

    {
        try
        {
            array[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return (0);
}
