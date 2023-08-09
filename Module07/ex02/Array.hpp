/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:09:34 by hyerimki          #+#    #+#             */
/*   Updated: 2023/08/09 15:59:27 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array{
    private:
        T *array;
        unsigned int size_n;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &array);
        ~Array();
        
        Array &operator=(const Array &array);
        T &operator[](const unsigned int n);
        unsigned int size(void);
};

template <typename T>
std::ostream &operator<<(std::ostream &o,Array<T>  &array)
{
    o << "[";
    for(unsigned int i=0;i< array.size();i++)
    {
        o << array[i];
        if (i < array.size() - 1)
            o << ",";
    }
    o << "]" << std::endl;
    return o;
}
#endif