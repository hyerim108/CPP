/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:45:33 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 17:30:51 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal{
    protected:
        std::string type;
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &wronganimal);
        WrongAnimal &operator=(const WrongAnimal &wronganimal);
        virtual ~WrongAnimal(void);

        void makeSound() const;
        const std::string& getType() const;
        void setType(const std::string &type);
};

#endif