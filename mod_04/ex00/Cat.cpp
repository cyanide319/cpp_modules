/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:48:30 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/14 12:55:41 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Cat.hpp"

//DEFAULT CONSTRUCTOR
Cat::Cat(){setType("Cat");}

//COPY CONSTRUCTOR
Cat::Cat(const Cat& new_object){*this = new_object;}

//DESTRUCTOR
Cat::~Cat(){}

//MEMBER FUNCTIONS
void	Cat::makeSound() const{std::cout<<"Meowmeow caliss"<<std::endl;}

//COPY ASSIGMENT OVERLOAD
Cat& Cat::operator=(const Cat& other){
    if (this != &other){
		this->type = other.type;
	}
    return (*this);
}
