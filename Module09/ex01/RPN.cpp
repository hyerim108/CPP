/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:46:29 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/27 15:55:36 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void){}


RPN::RPN(const RPN &r)
{
    *this = r;
}

RPN &RPN::operator=(const RPN &b) 
{
    (void)b;
    return (*this);
}

RPN::~RPN(void) {}

bool isOperater(char token){
    return (token == '+' || token == '-' || token == '*' || token == '/');
}

int calculator(char token, int a, int b)
{
    if (token == '+')
        return (a + b);
    else if (token == '-')
        return (a - b);
    else if (token == '*')
        return (a * b);
    else if (token == '/')
    {
        //나누는 숫자가 0 인경우도 생각! b = 0
        if (b == 0) throw(std::invalid_argument("Error : Cannot divide by zero"));
        return (a / b);
    }
    throw (std::invalid_argument("Error : unusable opperator"));
}

void RPN::formRPN(std::string input)
{
    std::stack<int> stack;
    for(size_t i = 0;i < input.length();i++)
    {
        if (isdigit(input[i])) //숫자일경우 push
            stack.push(input[i] - '0');
        else if (isOperater(input.at(i)) && stack.size() > 1)
        {
            //입력문자가 연산자일경우, 최상위 두개의 숫자를 꺼내 연산
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();

            int result = calculator(input.at(i), b, a);
            stack.push(result);
        }
        else if (isspace(input[i]))
            continue;
        else
            throw std::invalid_argument("Invalid input");
    }
    if (stack.size() != 1)
        throw std::invalid_argument("too much argument");
    std::cout << stack.top() <<  std::endl;
}
