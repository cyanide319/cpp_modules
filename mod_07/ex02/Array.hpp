/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:28:48 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/06/13 12:17:18 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array{
	public:
		Array();
		Array(unsigned int lenght);
		Array(const Array& new_object);
		~Array();

		unsigned int	size();

		Array& operator=(const Array& other);
		Array& operator[](const Array& other);
	private:
		T _array[];
};

#endif