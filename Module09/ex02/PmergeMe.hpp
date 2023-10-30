/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:17:15 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/30 12:53:11 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <list>

class PmergeMe{
    private:
        std::vector<int> v;
        std::vector<std::pair<int, int> > vp;
	    std::vector<int> vs;
        
        std::list<int> list;
        std::list<std::pair<int, int> > lp;
        std::list<int> ls;
        
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &r);
        PmergeMe &operator=(const PmergeMe &r);
        ~PmergeMe(void);

        PmergeMe(char **av);
        double vectorPmergeMe();
        double listPmergeMe();
        void pritArray();
};
#endif