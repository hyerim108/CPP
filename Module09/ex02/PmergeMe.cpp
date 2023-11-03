/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:17:10 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/30 16:34:02 by hyerimki         ###   ########.fr       */
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

// int Jacobsthal(int n) {
//     static std::vector<int> cache(n + 1, -1);
    
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     if (cache[n] != -1) return cache[n];

//     return cache[n] = Jacobsthal(n - 1) + Jacobsthal(n - 2) * 2;
// }
std::vector<int> Jacobsthal(int n) {
    std::vector<int> jacobsthal(n);
    jacobsthal[0] = 1;
    for (int i = 1; i < n; i++) {
        jacobsthal[i] = 1 + 2 * jacobsthal[i-1];
    }
    return jacobsthal;
}

double PmergeMe::vectorPmergeMe() {
    clock_t start = clock();

    // 벡터 사이즈만큼 나누어주기
    for (size_t i = 0; i < v.size(); i++) {
        if (i == v.size() -1 && v.size() % 2)
            vp.push_back(std::make_pair(-1, v[i]));
        else {
            vp.push_back(std::make_pair(v[i], v[i + 1]));
            i++;
        }
    }
    for (std::vector<std::pair<int, int> >::iterator it = vp.begin(); it != vp.end(); ++it) {
    std::cout << "Pair: (" << it->first << ", " << it->second << ")" << std::endl;
}

    // 두 쌍 중 큰 순으로 바꾸기
    for (std::vector<std::pair<int, int> >::iterator it = vp.begin(); it != vp.end(); ++it) {
        if ((*it).first < (*it).second)
            std::swap((*it).first, (*it).second);
    }
    std::cout << "----------" << std::endl;
for (std::vector<std::pair<int, int> >::iterator it = vp.begin(); it != vp.end(); ++it) {
    std::cout << "Pair: (" << it->first << ", " << it->second << ")" << std::endl;
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
    std::cout << "----------" << std::endl;
    for (std::vector<std::pair<int, int> >::iterator it = vp.begin(); it != vp.end(); ++it) {
        std::cout << "Pair: (" << it->first << ", " << it->second << ")" << std::endl;
    }
    int n = vp.size();
    std::vector<int> jacobsthal = Jacobsthal(n);

    // Jacobsthal 수열에 따라 mainChain에 삽입
    for (int i = 0; i < n; i++) {
        size_t idx = jacobsthal[i];
        if (idx < vp.size() && vp[idx].first != -1) {
            vs.push_back(vp[idx].first);
            vp[idx].first = -1;
        }
        if (idx < vp.size() && vp[idx].second != -1) {
            std::vector<int>::iterator sort = std::lower_bound(vs.begin(), vs.end(), vp[idx].second);
            vs.insert(sort, vp[idx].second);
            vp[idx].second = -1;
        }
    }

    for(size_t i=0;i<vs.size();i++)
        std::cout << " " << vs[i];
    std::cout << std::endl;
//     for(std::vector<std::pair<int, int> >::iterator it = vp.begin(); it != vp.end(); it++)
//     {
//         if ((*it).first != -1)
//             vs.push_back((*it).first);
//     }
//     std::cout << "----------" << std::endl;
//     for(size_t i =0;i<vs.size();i++)
//         std::cout << " " << vs[i];
//     std::cout << std::endl;
// for(std::vector<std::pair<int, int> >::iterator it = vp.begin(); it != vp.end(); it++)
//     {
//         std::vector<int>::iterator sort = std::lower_bound(vs.begin(), vs.end(), (*it).second);
//         vs.insert(sort, (*it).second);
//     }
    // int n = vp.size();
    // for (int i = 0; i < n; i++) {
    //     size_t idx = Jacobsthal(i); // Jacobsthal 수열을 사용
    //     std::cout << "idx : " << idx << std::endl;
    //     if (idx < vp.size() && vp[idx].first != -1) {
    //         vs.push_back(vp[idx].first);
    //         std::cout << "first : " << vp[idx].first << std::endl;
    //         vp[idx].first = -1;
    //     }
    //     if (idx < vp.size() && vp[idx].second != -1) {
    //         vs.push_back(vp[idx].second);
    //         std::cout << "second : " << vp[idx].second << std::endl;
    //         vp[idx].second = -1;
    //     }
    // }
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
    
    for(std::list<std::pair<int, int> >::iterator it = lp.begin(); it != lp.end(); it++)
    {
        std::list<std::pair<int, int> >::iterator next = it;
        ++next;
        if(next != lp.end())
        {
            std::list<std::pair<int, int> >::iterator point = next;
            std::list<std::pair<int, int> >::iterator prev = it;
            while ((*point).first < (*prev).first && point != lp.begin())
            {
                std::swap(*point, *prev);
                --point;
                if(point != lp.begin())
                {
                    prev = point;
                    --prev;
                }
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
        for (size_t i = 0; i < vs.size(); i++)
            std::cout << vs[i] << " ";
        std::cout << std::endl;
    }
    // else if (ls.size() == list.size())
    // {
    //     std::cout << "After: ";
    //     for(std::list<int>::iterator it = ls.begin(); it != ls.end(); it++)
    //         std::cout << " " << *it;
    //     std::cout << std::endl;
    // }
    else throw (std::invalid_argument("Error : No sorting has been done"));   
}