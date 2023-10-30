/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:17:06 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/30 14:19:51 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac <= 2)
    {
        std::cout << "Error: [./PmergeMe] [positive integer sequence as argument]" << std::endl;
        return (1);
    }

    try{
        PmergeMe merge(av);

        double timeVector = merge.vectorPmergeMe();
        double timeList = merge.listPmergeMe();
        
        merge.pritArray();
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector => " << std::fixed << std::setprecision(6) << timeVector << " us" << std::endl;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::list => " << std::fixed << std::setprecision(6) << timeList << " us" << std::endl;
    }catch(const std::invalid_argument& e)
    {
        std::cout << e.what() << '\n';
        return (1);
    }
    return 0;
}