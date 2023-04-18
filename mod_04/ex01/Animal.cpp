/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:21:05 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/14 12:56:54 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Animal.hpp"

//DEFAULT CONSTRUCTOR
Animal::Animal(){}

//COPY CONSTRUCTOR
Animal::Animal(const Animal& new_object){*this = new_object;}

//DESTRUCTOR
Animal::~Animal(){}

//GETTER
std::string	Animal::getType() const{return (type);}
//SETTER
void	Animal::setType(std::string new_val){this->type = new_val;}

//MEMBER FUNCTIONS
void	Animal::makeSound() const{std::cout<<"Whatever"<<std::endl;}

//COPY ASSIGMENT OVERLOAD
Animal& Animal::operator=(const Animal& other){
    if (this != &other){
		this->type = other.type;
	}
    return (*this);
}
