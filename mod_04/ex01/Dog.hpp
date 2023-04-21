/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:12:00 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/21 13:47:38 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#pragma once

#include<iostream>
#include"Animal.hpp"
#include"Brain.hpp"

class Dog: public Animal{
	public:
		Dog();
		Dog(std::string* new_ideas);
		Dog(const Dog& new_object);
		virtual ~Dog();

		// virtual Brain& get_brain() const;

		virtual void makeSound() const;

		Dog& operator=(const Dog& other);
	private:
		Brain*	_brain;
};

#endif