/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:58:56 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/31 13:31:57 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>

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

        bool check_input();
};

#endif
