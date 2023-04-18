/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:09:59 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/18 13:11:35 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once

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