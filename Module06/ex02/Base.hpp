/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:19:00 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/31 17:46:11 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <string>
#include <iostream>
#include <cstdlib> //srand

class Base{
    public:
        virtual ~Base(void);

        Base* generate(void);
        void identify(Base* p);
        void identify(Base& p);
};
#endif