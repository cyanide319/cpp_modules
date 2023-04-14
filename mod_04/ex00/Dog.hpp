/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:12:00 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/14 12:36:12 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#pragma once

#include<iostream>
#include"Animal.hpp"

class Dog: public Animal{
	public:
		Dog();
		Dog(const Dog& new_object);
		virtual ~Dog();

		virtual void makeSound() const;

		Dog& operator=(const Dog& other);
};

#endif