/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:02:33 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/03 15:39:50 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    std::string str;
    phonebook phone;
    
    while(str != "EXIT")
    {
        std::cout << "< Enter a command >" << std::endl;
        std::getline(std::cin, str);
        if (str == "ADD")
            phone.add();
        else if (str == "SEARCH")
            phone.search();
        else
            std::cout << "another command, Example < ADD, SEARCH, EXIT >" << std::endl;
        std::cout << std::endl;
    }
    return (0);
}