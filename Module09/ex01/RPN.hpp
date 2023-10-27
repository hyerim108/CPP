/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:46:35 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/27 15:54:42 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN{
    public:
        RPN(void);
        RPN(const RPN &r);
        RPN &operator=(const RPN &r);
        ~RPN(void);
        
        void formRPN(std::string input);
};

#endif