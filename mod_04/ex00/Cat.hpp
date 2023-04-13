/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:11:56 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/13 18:21:37 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#pragma once

#include<iostream>
#include"Animal.hpp"

class Cat: public Animal{
	public:
		Cat();
		Cat(const Cat& new_object);
		virtual ~Cat();

		virtual void makeSound()const;

		Cat& operator=(const Cat& other);
	// private:
	// 	const std::string	sound;
};

#endif