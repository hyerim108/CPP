/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:43:00 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/03 13:59:14 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        static const int bits = 8;
        int fix_var;
    public:
        Fixed(void);
        Fixed(const Fixed& fixed);
        
        Fixed &operator=(const Fixed &fixed);
        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif