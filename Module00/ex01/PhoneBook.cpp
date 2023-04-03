/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:46:07 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/03 16:29:07 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

phonebook::phonebook(void) : size(0) {}

void phonebook::add(void)
{
    int i = size++ % 8;
    contact[i].setContact();
    // std::cout << std::endl;
}
std::string fix_width(std::string str, int max)
{
    if (str.size() > max)
    {
        str.resize(max);
        str[str.size() - 1] = '.';
    }
    return (str);
}

int search_book(contact contact[8])
{
    char c = '0';
    int i = 0;
    std::string str;
    
    std::cout << "--------------------------------------------+" << std::endl;
	std::cout << "|     Index|First Name| Last name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
    
    while (++c <= '8')
    {
        i = 1;
        std::cout << "|";
        std::cout << std::setw(10) << c << "|";
        str = fix_width(contact[c - 1 - '0'].get_fname(), 10);
        std::cout << std::setw(10) << str << "|" ;
        str = fix_width(contact[c - 1 - '0'].get_lname(), 10);
        std::cout << std::setw(10) << str << "|" ;
        str = fix_width(contact[c - 1 - '0'].get_nick(), 10);
        std::cout << std::setw(10) << str << "|" ;
        std::cout << std::endl;
        std::cout << "+----------+----------+----------+----------+" << std::endl;
    }
    return (i);   
}

void print(contact contact)
{
    std::cout << "First Name : " << contact.get_fname() << std::endl;
    std::cout << "Last Name : " << contact.get_lname() << std::endl;
    std::cout << "Nickname : " << contact.get_nick() << std::endl;
    std::cout << "Phone Number : " << contact.get_phone_num() << std::endl;
    std::cout << "Darkest Secret : " << contact.get_secret() << std::endl;
}

void phonebook::search(void)
{
    std::string str;
    
    if (!search_book(contact))
    {
        std::cout << "Phonebook is empty!" << std::endl;
    }
    int i = -1;
    while (i != 0)
    {
        std::cout << "Select an index < range : 1 ~ 8 >  or EXIT '0' : ";
        if (std::getline(std::cin, str) && str != "")
        {
            if (str[0] >= '1' && str[0] <= '8' && str.size() == 1)
            {
                print(contact[str[0] - 1 - '0']);
                break;
            }
        }
        if (str == "0")
            i = 0;
        else if (str != "")
            std::cout << "Invalid Index!" << std::endl;
    }
}