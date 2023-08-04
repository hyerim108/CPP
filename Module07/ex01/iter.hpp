/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:58:45 by hyerimki          #+#    #+#             */
/*   Updated: 2023/08/04 15:57:58 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(const T *array, int len, void (*f)(const T &))
{
    int i = 0;
    while (i < len)
        f(array[i++]);
}

template <typename T>
void print(const T &data)
{
    std::cout << data << " ";
}
#endif