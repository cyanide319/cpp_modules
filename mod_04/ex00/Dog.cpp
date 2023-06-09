/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:55:54 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/14 14:17:09 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Dog.hpp"

//GREEN

//DEFAULT CONSTRUCTOR
Dog::Dog(){setType("Dog");std::cout<< GREEN_CL <<"Default dog constructor"<<std::endl << WHITE_CL;}

//COPY CONSTRUCTOR
Dog::Dog(const Dog& new_object){*this = new_object;std::cout<< GREEN_CL <<"Copy dog constructor"<<std::endl << WHITE_CL;}

//DESTRUCTOR
Dog::~Dog(){std::cout<< GREEN_CL <<"Default dog destructor"<<std::endl << WHITE_CL;}

//MEMBER FUNCTIONS
void	Dog::makeSound() const{std::cout<< GREEN_CL <<"Woofwoof motherfucker"<<std::endl << WHITE_CL;}

//COPY ASSIGMENT OVERLOAD
Dog& Dog::operator=(const Dog& other){
    if (this != &other){
		this->type = other.type;
	}
    return (*this);
}
