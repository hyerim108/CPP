/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:37:56 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 19:40:33 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    private:
        Brain *brain;
    public:
        Cat(void);
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);
        virtual ~Cat(void);

        virtual void makeSound() const;
        virtual const std::string& getType() const;
        const Brain &get_brain() const;
};

#endif