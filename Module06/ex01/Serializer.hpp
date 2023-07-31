/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:22:23 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/31 15:30:54 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp" //데이터 구조

class Serializer{
    private:
    public:
        /*canonical form*/
        Serializer(void);
        Serializer(const Serializer &s);
        Serializer &operator=(const Serializer &s);
        ~Serializer(void);
        
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif