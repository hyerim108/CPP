/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:17:10 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/30 16:02:27 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void){}


PmergeMe::PmergeMe(const PmergeMe &b) : v(b.v), vp(b.vp), vs(b.vs), list(b.list), lp(b.lp), ls(b.ls)
{
    *this = b;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &b) 
{
    if (this != &b){
        this->v = b.v;
        this->vp = b.vp;
        this->vs = b.vs;
        this->list = b.list;
        this->lp = b.lp;
        this->ls = b.ls;
    }
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
            list.push_back(n);
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
   
    // 두쌍중 작은순으로 바꾸기
    for(std::vector<std::pair<int, int> >::iterator it = vp.begin(); it!= vp.end();++it)
    {
        if ((*it).first > (*it).second)
            std::swap((*it).first, (*it).second);
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

    //첫번째 요소를 새로운 정렬된 벡터에 추가!
    for(std::vector<std::pair<int, int> >::iterator it = vp.begin(); it != vp.end(); ++it)
    {
        if((*it).first != -1)
            vs.push_back((*it).first);
    }
  
    //두번째 요소를 새로운 정렬된 벡터에 추가!
    for(std::vector<std::pair<int, int> >::iterator it = vp.begin(); it != vp.end(); ++it)
    {
        std::vector<int>::iterator sort;

        sort = std::lower_bound(vs.begin(), vs.end(), (*it).second);
        vs.insert(sort, (*it).second);
    }

    clock_t end = clock();
    return ((double)(end - start) / CLOCKS_PER_SEC);
}

double PmergeMe::listPmergeMe()
{
    clock_t start = clock();
    
    //두개로 나누기
    for(std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
    {
        if (it == list.begin() && list.size() % 2) //홀수
            lp.push_back(std::make_pair(-1, *it));
        else
        {
            std::list<int>::iterator next = it;
            next++;
            lp.push_back(std::make_pair(*it, *next));
            it++;
        }
    }

    //두개 자리 바꾸기
    for(std::list<std::pair<int, int> >::iterator it = lp.begin(); it != lp.end(); ++it)
    {
        if ((*it).first > (*it).second)
            std::swap((*it).first, (*it).second);
    }
    
    for(std::list<std::pair<int, int> >::iterator it = std::next(lp.begin()); it != lp.end(); it++)
    {
        std::list<std::pair<int, int> >::iterator point = it;
        std::list<std::pair<int, int> >::iterator prev = std::prev(it);
        while ((*point).first < (*prev).first)
        {
            std::swap(*point, *prev);
            if(prev != lp.begin())
            {
                point = prev;
                prev = std::prev(point);
            }
        }
    }

    for(std::list<std::pair<int, int> >::iterator it = lp.begin(); it != lp.end(); it++)
    {
        if ((*it).first != -1)
            ls.push_back((*it).first);
    }

    for(std::list<std::pair<int, int> >::iterator it = lp.begin(); it != lp.end(); it++)
    {
        std::list<int>::iterator sort = std::lower_bound(ls.begin(), ls.end(), (*it).second);
        ls.insert(sort, (*it).second);
    }

    clock_t end = clock();
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
    }else if (ls.size() == list.size())
    {
        std::cout << "After: ";
        for(std::list<int>::iterator it = ls.begin(); it != ls.end(); it++)
            std::cout << " " << *it;
        std::cout << std::endl;
    }
    else throw (std::invalid_argument("Error : No sorting has been done"));   
}