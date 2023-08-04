/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:58:40 by hyerimki          #+#    #+#             */
/*   Updated: 2023/08/04 16:00:15 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    int	intArray[] = {42, 41, 40, 39, 38};
	std::string	stringArray[] = {"hello", "im", "hyeimki"};
	float	floatArray[] = {42.42, 69.69, 42.69};

	std::cout << "iter int result:" << std::endl;
	::iter<int>(intArray, 5, ::print);

	std::cout << std::endl << std::endl << "iter string result" << std::endl;
	::iter<std::string>(stringArray, 3, ::print);

	std::cout<< std::endl << std::endl << "iter float result" << std::endl;
	::iter<float>(floatArray, 3, ::print);
	std::cout << std::endl;
}