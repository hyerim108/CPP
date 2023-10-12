/* ************************************************************************** */
/*                                                                             */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:37:50 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/12 12:39:34 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T search, int value)
{
    typename T::iterator it = std::find(search.begin(), search.end(), value);
    if (it == search.end())
        throw std::exception();
    return it;
}

#endif