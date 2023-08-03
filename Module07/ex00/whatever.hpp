/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:44:42 by hyerimki          #+#    #+#             */
/*   Updated: 2023/08/03 17:53:50 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
    T idx = a;
    a = b;
    b = idx;
}

template <typename T>
const T &max(T const &a, T const &b)
{
    return (a > b ? a : b);
}

template<typename T>
const T &min(T const &a, T const &b)
{
    return (a < b ? a : b);
}

#endif