/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:23:49 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/16 16:06:33 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>{
    public:
        MutantStack() : std::stack<T>(){};
        virtual ~MutantStack(){};

        MutantStack &operator=(const MutantStack &ms)
        {
            if (this != &ms)
                this->c = ms.c;
            return *this;
        };
        
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}

        const_iterator begin() const {return this->c.begin();}
        const_iterator end() const {return this->c.end();}
};

#endif