/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:30:48 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/01 16:30:48 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "stirng address : " << &str << std::endl;
    std::cout << "stringPTR address : " << stringPTR << std::endl;
    std::cout << "stringREF address : " << &stringREF << std::endl;
    std::cout << "stirng address : " << str << std::endl;
    std::cout << "stringPTR address : " << *stringPTR << std::endl;
    std::cout << "stringREF address : " << stringREF << std::endl;

    return (0);
}