/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:55:54 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/14 12:55:32 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Dog.hpp"

//DEFAULT CONSTRUCTOR
Dog::Dog(){setType("Dog");}

//COPY CONSTRUCTOR
Dog::Dog(const Dog& new_object){*this = new_object;}

//DESTRUCTOR
Dog::~Dog(){}

//MEMBER FUNCTIONS
void	Dog::makeSound() const{std::cout<<"Woofwoof motherfucker"<<std::endl;}

//COPY ASSIGMENT OVERLOAD
Dog& Dog::operator=(const Dog& other){
    if (this != &other){
		this->type = other.type;
	}
    return (*this);
}
