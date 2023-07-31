/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:28:52 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/31 18:07:13 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"

int main(void)
{
    Base* b = new Base();
    Base *a = b->generate();
    Base &c = *(b->generate());
    b->identify(a);
    b->identify(c);
    
    delete b;
    delete a;
    delete &c;
    
    return (0);
}