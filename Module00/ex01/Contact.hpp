/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:44:01 by hyerimki          #+#    #+#             */
/*   Updated: 2023/03/25 16:24:34 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class contact
{
    private:
        std::string fname;
        std::string lname;
        std::string nick;
        std::string phone_num;
        std::string secret;
    public:
        contact(void);
        void setContact(void);
        std::string get_fname(void);
        std::string get_lname(void);
        std::string get_phone_num(void);
        std::string get_nick(void);
        std::string get_secret(void);
};

#endif