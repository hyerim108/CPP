/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:28:56 by hyerimki          #+#    #+#             */
/*   Updated: 2023/08/03 13:58:52 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;
    std::cout << &data << std::endl;
    Serializer serialize;
    std::cout << serialize.serialize(&data) << std::endl;
    std::cout << serialize.deserialize(serialize.serialize(&data)) << std::endl;
}