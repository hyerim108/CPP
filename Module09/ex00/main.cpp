/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:27:31 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/30 14:43:35 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    std::map<std::string, float> map;
    
    if (ac != 2)
    {
        std::cout << "Argument Error : [./btc] [txt file name] " << std::endl;
        return (1);
    }
    
    std::ifstream inputdata("data.csv"); //파일 읽기 입력스트림 생성
    if (!inputdata.is_open()){ //파일 오픈 -> 파일이 제대로 열리지않았다면 false반환
        std::cout << "Error : data.csv file not found" << std::endl;
        return (1);
    }
    //data.csv파일의 데이터를 map 컨테이너에 저장해 줄것이다.
    map = BitcoinExchange::save_data("data.csv");
    
    return BitcoinExchange::find_data(av[1], map);
}