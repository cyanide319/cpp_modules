/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:37:12 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/06/13 17:48:38 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(): _size(0){_array = new T[0];}

template<typename T>
Array<T>::Array(unsigned int lenght): _size(lenght){_array = new T[lenght];}

template<typename T>
Array<T>::Array(const Array& new_object){
	this->_array = new T[_size];
	int i = 0;
	while(i < _size){
		this->_array[i] = new_object->_array[i];
		i++;
	}
}

template<typename T>
Array<T>::~Array(){delete[] _array;}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){
	if(this != &other){
		delete[] _array;
        this->_size = other._size;
		this->_array = new T[this->_size];
		int i = 0;
		while(i < _size){
			this->_array[i] = other->_array[i];
			i++;
		}
    }
    return(*this);
}

// template<typename T>
// unsigned int	Array<T>::size(){}

// template<typename T>
// Array& Array<T>::operator[](const Array& other){}
