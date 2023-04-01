/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:44:02 by hyerimki          #+#    #+#             */
/*   Updated: 2023/04/01 23:37:41 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char **av)
{   
    if (ac != 4)
    {
        std::cout << "Example : ./sed [filename] [s1] [s2]" << std::endl;
        return  (0);
    }
    std::ifstream infile;
    std::ofstream outfile;
    std::string filename = av[1];
    std::string str1 = av[2];
    std::string str2 = av[3];
    
    infile.open(filename);
    if (infile.fail())
    {
        std::cerr << "Error : no such file or directory ["  << filename << "]" << std::endl;
        return (1);
    }
    std::string refile = filename + ".replace";
    outfile.open(refile);

    if (outfile.fail())
    {
        std::cerr << "Error : no such file or directory ["  << refile << "]" << std::endl;
        return (1);
    }
    std::string save_str = "";
    std::string buffer_str = "";
    while(!infile.eof())
    {
        getline(infile, buffer_str);
        save_str += buffer_str;
        if (!infile.eof())
            save_str += '\n';
    }
    infile.close();
    size_t index = save_str.find(str1);
    while (index != std::string::npos)
    {
        save_str.erase(index, str1.length());
        save_str.insert(index, str2);
        index = save_str.find(str1, index + str2.length());
    }
    outfile << save_str;
    outfile.close();

    return (0);
}