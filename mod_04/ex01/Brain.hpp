/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:27:37 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/18 12:46:36 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#pragma once

#include<iostream>

class Brain{
	public:
		Brain();
		Brain(const Brain& new_object);
		virtual ~Brain();

		std::string	get_ideas(int i) const;

		void	set_ideas(int i, std::string new_val);

		Brain& operator=(const Brain& other);
	private:
		std::string	ideas[100];

};

#endif