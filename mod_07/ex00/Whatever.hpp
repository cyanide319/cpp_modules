/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:42:52 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/06/08 08:59:35 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "color.h"
#include <iostream>


template <typename T>
void swap(T& var1, T& var2){
	T temp;
	temp = var1;
	var1 = var2;
	var2 = temp;
};
template <typename T>
T&	min(T& var1, T& var2){
	if (var1 < var2)
		return (var1);
	else
		return (var2);
};
template <typename T>
T&	max(T& var1, T& var2){
	if (var1 > var2)
		return (var1);
	else
		return (var2);
};

#endif