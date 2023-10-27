/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:27:36 by hyerimki          #+#    #+#             */
/*   Updated: 2023/10/27 12:33:56 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::save_data(std::string data){
    //주어진 파일명을 사용하여 데이터를 읽고 map에 저장하여 반환
    std::map<std::string, float> map;
    std::ifstream inputdata(data);
    std::string line;
    
    getline(inputdata, line); //첫줄은 헤드로 한번 지나가줌
    while(getline(inputdata, line))
    {
        std::string data = line.substr(0,line.find(","));
        float value = atof((line.substr(line.find(",") + 1, line.find("\n"))).c_str());
        map.insert(std::pair<std::string, float>(data, value));
    }// 한줄씩읽은 날짜에 값을넣고 map을 반환
    return (map);
}

bool is_valid_input(std::string input)
{
    //날짜와 값이 잘 들어왔는지 확인
    if (input.find(" | ") != 10) return false;
    //날짜 형식은 YYYY-MM-DD 4와 7 - 나머지는 숫자인지 확인
    for(int i=0;i<10;i++)
    {
        if ((i== 4 || i == 7) && input[i] != '-'){
            std::cout << input[i] << std::endl;
            return false;
        }
        else if (input[i] != '-' && isdigit(input[i]) == 0) return false;
    }
    //| 이문자 다음도 값이 맞는지 확인 
    int i = input.find(" | ") + 3;
    while(input[i] != '\0')
    {
        if (input[i] != '.' && input[i] != '-' && std::isdigit(input[i]) == 0)
            return false;
        i++;
    }
    return true;
}

bool is_valid_data(int y, int m, int d)
{
    // 년, 월, 일이 유효한지 확인한다.
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > 31) return false;
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)){
        if (d > 29 && m == 2) return false;
    } else if (d > 28 && m == 2) return false;
    if (m == 4 || m == 6 || m == 9 || m == 11) return (d<=30);
    return true;
}

int BitcoinExchange::find_data(std::string file, std::map<std::string, float> map){
    (void)map;
    std::ifstream inputfile(file); // 파일을 열고 파일스트림객체생성
    std::string line; // 한줄씩저장할 문자열
    
    if (!inputfile.is_open())
    {
        std::cout << "Error : file does not exist" << std::endl;
        return (1);
    }
    getline(inputfile, line);
    while(getline(inputfile, line)) //file의 모든 줄을 순회한다.
    {
        if (!is_valid_input(line)) // 유효한 입력이 아닐때
            std::cout << "Error: bad input => " << line << std::endl;
        
        else if (!is_valid_data(std::stoi(line.substr(0,4)), stoi(line.substr(5,2)), stoi(line.substr(8,2))))
            std::cout<< "Error: invalid data => " << line <<  std::endl;
        else{
            std::string date = line.substr(0, line.find(" | "));
            std::string value = line.substr(line.find(" | ") + 3, line.find("\n"));
            if (value.c_str()[0] == '-') //값이 음수일시
                std::cout << "Error: not a positive number." << std::endl;
            else if((unsigned int)std::atoi(value.c_str()) > 1000)
                std::cout << "Error: too large a number." << std::endl;
            else{
                std::map<std::string,float>::iterator it;
                it = map.upper_bound(date);
                if (it != map.begin()) it--;
                std::cout << date << " => " << value << " = " << (it->second * atof(value.c_str())) << std::endl;
            }
        }
    }
    return (0);
}