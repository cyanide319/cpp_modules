/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 02:11:31 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/05 12:34:47 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
bool easyfind(T& container, int to_find){
	typename T::const_iterator iterator = std::find(container.begin(), container.end(), to_find);
	if (iterator != container.end())
			return (true);
	return (false);
};

#endif