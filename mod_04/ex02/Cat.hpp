/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:11:56 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/19 15:02:17 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#pragma once

#include<iostream>
#include"Animal.hpp"
#include"Brain.hpp"

class Cat: public Animal{
	public:
		Cat();
		Cat(std::string* new_ideas);
		Cat(const Cat& new_object);
		virtual ~Cat();

		virtual Brain& get_brain() const;

		virtual void makeSound()const;

		Cat& operator=(const Cat& other);
	private:
		Brain	*_brain;

};

#endif