/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:38:01 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 19:41:24 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    private:
        Brain *brain;
    public:
        Dog(void);
        Dog(const Dog &dog);
        Dog &operator=(const Dog &dog);
        virtual ~Dog(void);

        virtual void makeSound() const;
        virtual const std::string& getType() const;
        const Brain &get_brain() const;
};

#endif