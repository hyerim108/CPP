/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:45:21 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 17:30:44 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    private:
        std::string type;
    public:
        WrongCat(void);
        WrongCat(const WrongCat &wrongcat);
        WrongCat &operator=(const WrongCat &wrongcat);
        virtual ~WrongCat(void);

        void makeSound() const;
        const std::string& getType() const;
        void setType(const std::string &type);
};

#endif