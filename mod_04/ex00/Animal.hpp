/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:09:59 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/14 14:13:37 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once

#define BLUE_CL "\033[1;36m"
#define WHITE_CL "\033[0;37m"
#define RED_CL "\033[0;31m"
#define YELLOW_CL "\033[0;33m"
#define PINK_CL "\033[38;2;255;192;203m"
#define GREEN_CL "\033[0;32m"

#include<iostream>

class Animal{
	public:
		Animal();
		Animal(const Animal& new_object);
		virtual ~Animal();

		//GETTER/SETTER
		std::string		getType() const;

		void			setType(std::string new_val);
		//MEMBER FUNCTIONS
		virtual void	makeSound() const;

		Animal& operator=(const Animal& other);
	protected:
		std::string	type;
};

#endif