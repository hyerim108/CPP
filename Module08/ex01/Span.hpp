/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:40:36 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/13 15:33:00 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>
#include <algorithm>

class Span{
    private:
        unsigned int N;
        std::vector<int> v;
    public:
        Span(void); //기본생성자
        Span(unsigned int N);
        Span(const Span &span); //복사 생성자
        ~Span(); //소멸자
        Span &operator=(const Span &span); //대입연산자

        void addNumber(int num);
        int shortestSpan(); //최단범위
        int longestSpan(); //최장범위
};

#endif