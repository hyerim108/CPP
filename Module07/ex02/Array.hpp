/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:09:34 by hyerimki          #+#    #+#             */
/*   Updated: 2023/08/04 19:40:57 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

class Array{
    private:
        T *array;
        unsigned int size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &c);
        ~Array();
        
};
#endif