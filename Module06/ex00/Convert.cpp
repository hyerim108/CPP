/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:58:58 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/29 16:47:01 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(void)
{
}

Convert::Convert(std::string in) : in(in)
{
    if(ft_error() == 1)
        return ;
    // ft_int();
    // ft_char();
    // ft_float();
    // ft_double();
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
    if (num >= 32 && num <= 126)
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void Convert::ft_float()
{
    char* endPtr;
    float num = std::strtof(this->in.c_str(), &endPtr);
    if (num >= 32 && num <= 126)
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void Convert::ft_double()
{
    char* endPtr;
    double num = std::strtod(this->in.c_str(), &endPtr);
    if (num >= 32 && num <= 126)
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

int Convert::ft_error()
{
    if (this->in == "nanf" || this->in == "+inff" || this->in == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << std::endl;
        std::cout << "double: " << std::endl;
        return (1);
    }
    else if (this->in == "nan" || this->in == "+inf" || this->in == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << std::endl;
        std::cout << "double: " << std::endl;
        return (1);
    }
    long int num = std::atol(this->in.c_str());
    if (num > 2147483647 || num < MIN_INT)
    {
        std::cout << "Exception : num overflow" << std::endl;
        return (1);
    }
    return (0);
}