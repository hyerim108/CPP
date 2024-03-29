/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:38:19 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/03 14:06:18 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        static const int bits = 8;
        int fix;
    public:
        Fixed(void);
        Fixed(const int fix);
        Fixed(const float fix);
        Fixed(const Fixed &fixed);
        
        Fixed &operator=(const Fixed &fixed);
        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fix);

#endif