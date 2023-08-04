/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:37:05 by hyerimki          #+#    #+#             */
/*   Updated: 2023/08/04 19:40:43 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array::Array() : array(NULL), size(0){};

template <typename T>
Array::Array(unsigned int n) : array(new T[n]), size(n) {};

Array::~Array(){
    
};