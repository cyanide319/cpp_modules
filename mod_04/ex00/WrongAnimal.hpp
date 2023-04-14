/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:36:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/14 12:52:40 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#pragma once

#include<iostream>

class WrongAnimal{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& new_object);
		virtual ~WrongAnimal();

		//GETTER/SETTER
		std::string		getType() const;

		void			setType(std::string new_val);
		//MEMBER FUNCTIONS
		void			makeSound() const;

		WrongAnimal& operator=(const WrongAnimal& other);
	protected:
		std::string	type;
};

#endif