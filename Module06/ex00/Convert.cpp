/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:58:58 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/29 15:55:13 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"


Convert::Convert(void)
{
}

Convert::Convert(std::string in) : in(in)
{
    ft_char();
    ft_int();
}

Convert::Convert(const Convert &convert) : in(convert.in)
{
    std::cout << "Convert copy was constructed" << std::endl;
    *this = convert;
}

Convert &Convert::operator=(const Convert &convert) 
{
    std::cout << "Assignment Operator for Convert call" << std::endl;
    if (this == &convert)
    {
        return (*this);
    }
    return (*this);
}

Convert::~Convert(void)
{
}

void Convert::ft_char()
{
    if ((this->in[0] >= 32 && this->in[0] <= 47) || (this->in[0] >= 57 && this->in[0] <= 126))
        std::cout << "char: " << this->in << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(in[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(in[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(in[0]) << ".0" << std::endl;
}

void Convert::ft_int()
{
    int num = std::atoi(this->in.c_str());
    std::cout << num << std::endl;
}