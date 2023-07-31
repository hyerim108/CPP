/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:22:21 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/31 15:31:17 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer(void)
{
}

Serializer::Serializer(const Serializer &s)
{
    std::cout << "CoSerializernvert copy was constructed" << std::endl;
    *this =  s;
}

Serializer &Serializer::operator=(const Serializer &s) 
{
    std::cout << "Assignment Operator for Convert call" << std::endl;
    (void) s;
    if (this == &s)
        return (*this);
    return (*this);
}

Serializer::~Serializer(void)
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}