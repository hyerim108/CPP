/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:29:52 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 18:58:48 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain created defalut constructor." << std::endl;
}

Brain::Brain(const Brain &brain)
{
    for(int i=0;i<100;i++)
        this->ideas[i] = brain.ideas[i];
    *this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
    std::cout << "Assignment Operator for Brain call" << std::endl;
    if (this != &brain)
    {
        for(int i=0;i<100;i++)
            this->ideas[i] = brain.ideas[i];
    }
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << "Brain destoryed." << std::endl;
}