/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:44:08 by hyerimki          #+#    #+#             */
/*   Updated: 2023/03/25 16:24:41 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

contact::contact(void) : fname(""), lname(""), phone_num(""), nick(""), secret("") {}

void anysome_input(std::string *str, std::string input)
{
    while(str->empty())
    {
        std::cout << input;
        std::getline(std::cin, *str);
        if(std::cin.eof())
            break;
    }
}

void contact::setContact(void)
{
    fname.clear();
    anysome_input(&fname, "Enter a first name : ");
    lname.clear();
    anysome_input(&lname, "Enter a last name : ");
    nick.clear();
    anysome_input(&nick, "Enter a nickname : ");
    phone_num.clear();
    anysome_input(&phone_num, "Enter a phone number : ");
    secret.clear();
    anysome_input(&secret, "Enter a darkest secret : ");
}

std::string contact::get_fname(void)
{
    return fname;
}

std::string contact::get_lname(void)
{
    return lname;
}
std::string contact::get_phone_num(void)
{
    return phone_num;
}

std::string contact::get_nick(void)
{
    return nick;
}

std::string contact::get_secret(void)
{
    return secret;
}