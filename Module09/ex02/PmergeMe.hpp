/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:17:15 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/28 17:34:51 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <iomanip>

class PmergeMe{
    private:
        std::vector<int> v;
        std::vector<std::pair<int, int> > vp;
	    std::vector<int> vs;
        
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &r);
        PmergeMe &operator=(const PmergeMe &r);
        ~PmergeMe(void);

        PmergeMe(char **av);
        double vectorPmergeMe();
        void pritArray();
};
#endif