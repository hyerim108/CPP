/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:40:46 by hyerimki          #+#    #+#             */
/*   Updated: 2023/03/25 16:04:51 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <string>

#include "Contact.hpp"

class phonebook
{
    private:
        int size;
        contact contact[8];
    public:
        phonebook(void);
        void add(void);
        void search(void);
};

#endif