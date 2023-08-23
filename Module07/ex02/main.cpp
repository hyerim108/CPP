/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:10:02 by hyerimki          #+#    #+#             */
/*   Updated: 2023/08/23 17:23:47 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

#define MAX_VAL 750
int main(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
    
    // std::cout << "< int array > " << std::endl;
	// Array <int> array(10);

	// std::cout << "< array using [] operator >" << std::endl;
    // std::cout << "array Size : " << array.size() << std::endl;
	// for(unsigned int i = 0; i < array.size(); i++)
	// 	array[i] = i + 1;
	// std::cout << array << std::endl;

    // std::cout << "< string array > " << std::endl;
	// Array <std::string> array_string(3);

	// std::cout << "< array using [] operator >" << std::endl;
    // std::cout << "array Size : " << array_string.size() << std::endl;
	// for(unsigned int i = 0; i < array_string.size(); i++)
	// 	array_string[i] = 'a' + i;
	// std::cout << array_string << std::endl;
    
    // Array<int> copy_int(10);
    // copy_int = array;
    
    // copy_int[0] = -1;
    // std::cout << copy_int << std::endl;

    // Array<std::string> copy_string;
    // copy_string = array_string;
    // array_string[0] = "grape";
    // array_string[1] = "banana";
    // array_string[2] = "watermelon";
    // std::cout << copy_string << std::endl;
    // std::cout << array_string << std::endl;

    // {
    //     try
    //     {
    //         array[-2] = 0;
    //     }
    //     catch(const std::exception& e)
    //     {
    //         std::cerr << e.what() << '\n';
    //     }
    // }
    // return (0);
}
