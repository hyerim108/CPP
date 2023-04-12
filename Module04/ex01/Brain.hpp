/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:29:49 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/12 18:35:16 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain{
    private:
        std::string ideas[100];
    public:
        Brain(void);
        Brain(const Brain &brain);
        Brain &operator=(const Brain &brain);
        virtual ~Brain(void);
};

#endif