/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:40:30 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/19 19:56:53 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) {} //디폴트

Span::Span(unsigned int N) : N(N)
{
    std::cout << "Span was constructed with N" << std::endl;
}

Span::Span(const Span &span)
{
    std::cout << "Span copy was constructed" << std::endl;
    *this = span;
}

Span &Span::operator=(const Span &span) 
{
    std::cout << "Assignment Operator for Span call" << std::endl;
    this->N = span.N;
    this->v = span.v;
    return (*this);
}

Span::~Span(void) {}

void Span::addNumber(int num) //벡터에 숫자 추가해주는 메소드
{
    if (v.size() >= N)
        throw std::out_of_range("Error : vector is already full");
    v.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if(v.size() >= N || std::distance(begin, end) > (long)N - (long)v.size())
        throw std::out_of_range("Error : vector is already full");
    v.insert(v.end(), begin, end);
}

int Span::shortestSpan(){
    if (v.size() <= 1)
       throw std::out_of_range("Error : vector is not enough");
    std::sort(v.begin(), v.end());
     int shortest = v[1] - v[0];
     for (unsigned int i = 0; i < v.size() - 1; i++) {
         if ((v[i + 1] - v[i]) < shortest) {
             shortest = (v[i + 1] - v[i]);
         }
     }
     return shortest;
}
int Span::longestSpan(){
    if (v.size() <= 1)
        throw std::out_of_range("Error : vector is not enough");
    std::sort(v.begin(), v.end());
     return v[v.size() -1] - v[0];
}