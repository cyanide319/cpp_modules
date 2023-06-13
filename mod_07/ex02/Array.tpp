/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:37:12 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/06/13 17:09:28 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _size(0){_array = new T[0];}

template <typename T>
Array<T>::Array(unsigned int lenght): _size(lenght){_array = new T[lenght];}

//Array::Array(const Array& new_object){} 

//Array::~Array(){}

//unsigned int	Array::size(){}

//Array& Array::operator=(const Array& other){}

//Array& Array::operator[](const Array& other){}
