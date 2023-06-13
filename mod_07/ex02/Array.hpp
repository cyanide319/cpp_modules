/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:28:48 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/06/13 17:46:34 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array{
	public:

		Array();
		Array(unsigned int lenght);
		Array(const Array<T>& new_object);
		~Array();

		unsigned int	size();

		Array<T> operator=(const Array<T>& other);
		T& operator[](unsigned int index);
	private:
		T*				_array;
		unsigned int	_size;
};

#include "Array.tpp"

#endif