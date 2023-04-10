/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:37:56 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/10 17:54:44 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>

class Cat{
    public:
        Cat(void);
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);
        ~Cat(void);
};

#endif