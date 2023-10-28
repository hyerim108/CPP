/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:27:34 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/28 17:53:54 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib> 
#include <string>

class BitcoinExchange{
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &b);
        BitcoinExchange &operator=(const BitcoinExchange &b);
        ~BitcoinExchange(void);
    
        static std::map<std::string, float> save_data(std::string data);
        static int find_data(std::string file, std::map<std::string, float> map);
};

#endif