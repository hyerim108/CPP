/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:18:57 by hyerimki          #+#    #+#             */
/*   Updated: 2023/07/31 18:15:40 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
}

Base* Base::generate(void)
{
    //A,B,C를 랜덤인스턴스, 인스턴스를 기본포인터로 반환
    std::srand(std::time(NULL));
    int i = std::rand() % 3;
    if (i == 0)
        return new A();
    else if (i == 1)
        return new B();
    else 
        return new C();
    return new A();
}

void Base::identify(Base* p)
{
    //A,B,C가 가리키는 객체의 실제유형을 인쇄
    std::cout << "<pointer>" << std::endl;
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void Base::identify(Base& p)
{
    //A,B,C가 가리키는 객체의 유형 인쇄.
    std::cout << "<reference>" << std::endl;
    try
    {
        if (&dynamic_cast<A&>(p))
            std::cout << "A" << std::endl;
    }catch(std::exception& e) {}
    try
    {
        if (&dynamic_cast<B&>(p))
            std::cout << "B" << std::endl;
    }catch(std::exception& e) {}
     try
    {
        if (&dynamic_cast<C&>(p))
            std::cout << "C" << std::endl;
    }catch(std::exception& e) {}
}