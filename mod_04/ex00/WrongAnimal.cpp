/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:48:27 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/14 12:57:03 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"WrongAnimal.hpp"

//DEFAULT CONSTRUCTOR
WrongAnimal::WrongAnimal(){}

//COPY CONSTRUCTOR
WrongAnimal::WrongAnimal(const WrongAnimal& new_object){*this = new_object;}

//DESTRUCTOR
WrongAnimal::~WrongAnimal(){}

//GETTER
std::string	WrongAnimal::getType() const{return (type);}
//SETTER
void	WrongAnimal::setType(std::string new_val){this->type = new_val;}

//MEMBER FUNCTIONS
void	WrongAnimal::makeSound() const{std::cout<<"This exercice suck"<<std::endl;}

//COPY ASSIGMENT OVERLOAD
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if (this != &other){
		this->type = other.type;
	}
    return (*this);
}