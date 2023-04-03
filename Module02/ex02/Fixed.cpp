/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:38:16 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/03 14:46:01 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : fix(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fix) : fix(fix << bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fix) : fix(roundf(fix * (1 << bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &fixed)
        fix = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return fix;
}

void Fixed::setRawBits(int const raw)
{
    fix = raw;
}

int Fixed::toInt(void) const
{
    return (fix >> bits);
}

float Fixed::toFloat(void) const
{
    return ((float)(fix) / (1 << bits));
}

std::ostream &operator<<(std::ostream &o, const Fixed &fix)
{
    return (o << fix.toFloat());
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return (fix > fixed.fix);
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (fix < fixed.fix);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (fix >= fixed.fix);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (fix <= fixed.fix);
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (fix == fixed.fix);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (fix != fixed.fix);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    return (this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    return (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    return (this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void)
{
    ++fix;
    return *this;
}

Fixed &Fixed::operator--(void)
{
    --fix;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++fix;
    
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --fix;
    
    return temp;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a >= b ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a <= b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a >= b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a <= b ? a : b);
}
