/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:37:05 by hyerimki          #+#    #+#             */
/*   Updated: 2023/08/23 17:24:11 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), size_n(0){};

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), size_n(n) {};

template <typename T>
Array<T>::Array(const Array<T> &array) : array(new T[array.size_n]), size_n(array.size_n)
{
    for(unsigned int i=0;i<array.size_n;i++)
        this->array[i] = array.array[i];
    *this = array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &array) 
{
    if (this != &array)
    {
        delete[] (this->array);
        this->size_n = array.size_n;
        this->array = new T[this->size_n];
        for(unsigned int i=0;i<array.size_n;i++)
            this->array[i] = array.array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array(){
    delete[] (this->array);
};

template <typename T>
T &Array<T>::operator[](const unsigned int n) const
{
    if (n < 0 || n >= this->size_n)
        throw std::exception();
    return this->array[n];
}

template <typename T>
unsigned int Array<T>::size(void) const{
    return (this->size_n);  
};