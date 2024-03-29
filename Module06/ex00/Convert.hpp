/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:58:56 by hyerimki          #+#    #+#             */
/*   Updated: 2023/08/02 19:50:25 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring> //strstr
#include <cctype>
#include <cstdio> //sscanf
#include <cstdlib> //atoi

#define MAX_INT 2147483647
#define MIN_INT -2147483648

class Convert{
    private:
        std::string in;
    public:
        /*canonical form*/
        Convert(void);
        Convert(const Convert &Convert);
        Convert &operator=(const Convert &convert);
        ~Convert(void);

        Convert(std::string in);
        void ft_char();
        void ft_int();
        void ft_float();
        void ft_double();
        int ft_error();
        int science();
        bool check_input();
};

#endif
