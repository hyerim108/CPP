/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:38:01 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/10 17:58:18 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>

class Dog{
    public:
        Dog(void);
        Dog(const Dog &dog);
        Dog &operator=(const Dog &dog);
        ~Dog(void);
};

#endif