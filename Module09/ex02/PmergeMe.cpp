/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:17:10 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/28 17:37:41 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void){}


PmergeMe::PmergeMe(const PmergeMe &b)
{
    *this = b;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &b) 
{
    (void)b;
    return (*this);
}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(char **av)
{
    std::cout << "Before:";
    for(int i=1;av[i];i++)
    {
        int n;
        if ((std::istringstream(av[i]) >> n) && n >= 0)
        {
            v.push_back(n);
            std::cout << " " << n;
        }
        else {
            std::cout << "..." << std::endl;
            throw (std::invalid_argument("Error : Wrong arguments"));
        }
    }
    std::cout << std::endl;
}

double PmergeMe::vectorPmergeMe()
{
    clock_t start = clock();
    //벡터 사이즈만큼 나누어주기
    for(size_t i = 0;i < v.size();i++)
    {
        if (i == 0 && v.size() % 2)
            vp.push_back(std::make_pair(-1,v[i]));
        else
        {
            vp.push_back(std::make_pair(v[i], v[i+1]));
            i++;
        }
    }
    //출력해보기
    for(size_t i=0; i<vp.size(); i++){
        std::cout << "Pair " << i+1 << ": (" << vp[i].first << ", " << vp[i].second << ")" << std::endl;
    }
    // 두쌍중 작은순으로 바꾸기
    for(std::vector<std::pair<int, int> >::iterator it = vp.begin(); it!= vp.end();++it)
    {
        if ((*it).first > (*it).second)
            std::swap((*it).first, (*it).second);
    }

    std::cout << "--------------------" << std::endl;
    //출력해보기
    for(size_t i=0; i<vp.size(); i++){
        std::cout << "Pair " << i+1 << ": (" << vp[i].first << ", " << vp[i].second << ")" << std::endl;
    }
    
    //첫번째 요소를 기준으로 정렬
    for(std::vector<std::pair<int, int> >::iterator it = vp.begin() + 1; it != vp.end(); ++it)
    {
        std::vector<std::pair<int, int> >::iterator point = it;
        std::vector<std::pair<int, int> >::iterator prev = it - 1;
        while((*point).first < (*prev).first)
        {
            std::swap(*point, *prev);
            if (prev != vp.begin())
            {
                point = prev;
                prev = point - 1;
            }
        }
    }

    std::cout << "--------------------" << std::endl;
    //출력해보기
    for(size_t i=0; i<vp.size(); i++){
        std::cout << "Pair " << i+1 << ": (" << vp[i].first << ", " << vp[i].second << ")" << std::endl;
    }

    //첫번째 요소를 새로운 정렬된 벡터에 추가!
    for(std::vector<std::pair<int, int> >::iterator it = vp.begin(); it != vp.end(); ++it)
    {
        if((*it).first != -1)
            vs.push_back((*it).first);
    }
    std::cout  << std::endl;
    //출력해보기
    for(size_t i=0; i<vs.size(); i++){
        std::cout  << vs[i] << " " ;
    }
    std::cout  << std::endl;
    //두번째 요소를 새로운 정렬된 벡터에 추가!
    for(std::vector<std::pair<int, int> >::iterator it = vp.begin(); it != vp.end(); ++it)
    {
        std::vector<int>::iterator sort;

        sort = std::lower_bound(vs.begin(), vs.end(), (*it).second);
        vs.insert(sort, (*it).second);
    }

    //출력해보기
    for(size_t i=0; i<vs.size(); i++){
        std::cout << vs[i] << " " ;
    }
    std::cout  << std::endl;
    clock_t end = clock();
    std::cout << start << " " << end << " " << (double)(end - start) << std::endl;
    return ((double)(end - start) / CLOCKS_PER_SEC );
}

void PmergeMe::pritArray()
{
    if (vs.size() == v.size())
    {
        std::cout << "After: ";
        for(std::vector<int>::iterator it = vs.begin(); it != vs.end(); ++it)
            std::cout << " " << *it;
        std::cout << std::endl;
    }
    else throw (std::invalid_argument("Error : No sorting has been done"));   
}